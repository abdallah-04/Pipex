#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf/ft_printf.h"

typedef struct s_command_info {
	char	**command_folders;
	char	*path;
	char	**command_args;
	char	*absolute_path;
} command_info;

void printenvs(char **env)
{
	int	i;
	i = 0;
	while (env[i++])
		printf("%s\n", env[i]);
}

char	*get_path(char **env)
{
	int	i;
	int	j;
	char	*path;

	i = 0;
	j = 0;
	while(env[i])
	{
		if (!(ft_strncmp(env[i], "PATH=", 5)))
		{
			path = ft_strdup(env[i]) + 5;
		}
		i++;
	}
	return (path);
}

char	*get_command_path(command_info *info)
{
	int	i;
	char	*str;

	i = 0;
	while (info->command_folders[i])
	{
		str = ft_strjoin(info->command_folders[i], "/");
		str = ft_strjoin(str,  info->command_args[0]);
		if(!access(str, X_OK))
			return (str);
		i++;
	}
	return (NULL);
}

int main(int argc, char **argv, char **env)
{
    int	fd_pipe[2];
    int	fd_infile;
    int fd_outfile;
    int	id;
    command_info command;

    if (argc != 5)
        return (1);

    if (pipe(fd_pipe) == -1)
        return (perror("pipe"), 1);

    id = fork();
    if (id == -1)
        return (perror("fork"), 1);

    if (id == 0)
    {
        fd_infile = open(argv[1], O_RDONLY);
        if (fd_infile == -1)
            return (perror(argv[1]), 1);
        dup2(fd_infile, 0);
        dup2(fd_pipe[1], 1);
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        command.path = get_path(env);
        command.command_folders = ft_split(command.path, ':');
        command.command_args = ft_split(argv[2], ' ');
        command.absolute_path = get_command_path(&command);
        execve(command.absolute_path, command.command_args, env);
        perror("execve");
    }
    else
    {
        fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd_outfile == -1)
            return (perror(argv[4]), 1);
        dup2(fd_pipe[0], 0);
        dup2(fd_outfile, 1);
        close(fd_pipe[0]);
        close(fd_pipe[1]);
        command.path = get_path(env);
        command.command_folders = ft_split(command.path, ':');
        command.command_args = ft_split(argv[3], ' ');
        command.absolute_path = get_command_path(&command);
        execve(command.absolute_path, command.command_args, env);
        perror("execve");
    }
    return (0);
}

