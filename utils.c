/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:57:57 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/08 11:30:46 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char **env)
{
	char *path;
	int i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			if (!path)
				return (NULL);
			break;
		}
		i++;
	}
	return (path);
}

char	*get_cmd_path(t_command_info *info)
{
	char	*str;
	int		i;

	i = 0;
	while (info->command_folders[i])
	{
		str = ft_strjoin(info->command_folders[i], "/");
		str = ft_strjoin(str, info->command_args[0]);
		if (!access(str, X_OK))
			return (str);
		i++;
	}
	return (NULL);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr || !arr[0])
		return;
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
	if (fd_pipe)
	{
		if (fd_pipe[0] != -1)
			close(fd_pipe[0]);
		if (fd_pipe[1] != -1)
			close(fd_pipe[1]);
	}
	if (fd_file != -1)
		close(fd_file);
	free_split(cmd.command_args);
	free_split(cmd.command_folders);
	free(cmd.absolute_path);
	free(cmd.path);
	perror("Error");
	exit(1);
}
