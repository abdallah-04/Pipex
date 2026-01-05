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
	// if (argc != 5)
	// 	return (0);
	int fd[2];
	if(pipe(fd) == -1){
		ft_printf("\nError: pipe!\n");
		exit(-1);
	}
	command_info command;
	command.path = get_path(env);
	command.command_folders = ft_split(command.path, ':');
	command.command_args = ft_split(argv[2], ' ');
	command.absolute_path = get_command_path(&command);
	if (!command.absolute_path)
		return (0);
	int id = fork();
	if (id == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] == -1)
			return (perror("open"), 1);
		dup2(fd[0], 0);
		execve(command.absolute_path, command.command_args, env);
	}
	else
	{
		command.command_args = ft_split(argv[3], ' ');
		command.absolute_path = get_command_path(&command);
		fd[1] = open(argv[4], O_RDONLY);
		if (fd[1] == -1)
			return (perror("open"), 1);
		dup2(fd[1], fd[0]);
		execve(command.absolute_path, command.command_args, env);
	}
}
