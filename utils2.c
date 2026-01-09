#include "pipex.h"

void    init_command(t_command_info *command, char **env)
{
	command->command_args = NULL;
	command->command_folders = NULL;
	command->absolute_path = NULL;
	command->env = env;
	command->path = get_path(command->env);
	if (!command->path)
	{
		free(command->path);
		perror("Error");
		exit(1);
	}
	command->command_folders = ft_split(command->path, ':');
	if (!command->command_folders)
	{
		free(command->path);
		free_split(command->command_folders);
		perror("Error");
		exit(1);
	}
}

int return_error(void)
{
	perror("Error");
	return (0);
}

void    ignore_parents(int *fd_pipe)
{
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	wait(NULL);
	wait(NULL);
}