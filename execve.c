#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

struct s_command_info {
        char **command_folders;
        char *path;
        char **command_args;
        char *absolute_path;
};


void printenvs(char **env)
{
	int i = 0;
	while (env[i++])
		printf("%s\n", env[i]);
}

char	*get_path(char **env)
{
	int i=0;
	int j =0;
	char *path;
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

char	*get_command_path(struct s_command_info *info)
{
	int i;
	i = 0;
	while (info->command_folders[i])
	{
		
		char *str = ft_strjoin(info->command_folders[i], "/");
		//printf("%s\n", str);
		str = ft_strjoin(str,  info->command_args[0]);
		//printf("%s\n", str);
	       if(!access(str, X_OK))
		       return (str);
	       i++;
	}
	return (NULL);
}

#include <fcntl.h>
int main(int argc, char **argv, char **env)
{
	if (argc != 2)
		return (0);
	struct s_command_info command;
	command.path = get_path(env);	
	command.command_folders = ft_split(command.path, ':');
	command.command_args = ft_split(argv[1], ' ');
	command.absolute_path = get_command_path(&command);
	if (!command.absolute_path)
		return (0);
	int id = fork();
	if (id == 0)
	{
	int fd = open("outfile", O_WRONLY|O_CREAT);
	dup2(fd, 1);
	execve(command.absolute_path, command.command_args, env);
	}
}
