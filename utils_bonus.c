#include "pipex_bonus.h"

char	*get_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			if (!path)
				return (NULL);
			break ;
		}
		i++;
	}
	return (path);
}

char	*get_cmd_path(t_command_info *info)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	if (!info->command_args || !info->command_args[0]
		|| info->command_args[0][0] == '\0')
		return (NULL);
	if (info->command_args[0][0] == '/' && access(info->command_args[0], X_OK) == 0)
    	return (ft_strdup(info->command_args[0]));
	while (info->command_folders[i])
	{
		tmp = ft_strjoin(info->command_folders[i], "/");
		if (!tmp)
			return (NULL);
		str = ft_strjoin(tmp, info->command_args[0]);
		free(tmp);
		if (!access(str, X_OK))
			return (str);
		free(str);
		i++;
	}
	return (NULL);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	clean_and_exit(t_command_info cmd, int *fd_pipe, int fd_file)
{
	close_fds(fd_pipe, fd_file);
	if (cmd.command_args)
		free_split(cmd.command_args);
	if (cmd.command_folders)
		free_split(cmd.command_folders);
	if (cmd.absolute_path)
		free(cmd.absolute_path);
	if (cmd.path)
		free(cmd.path);
	perror("Error");
	exit(1);
}
