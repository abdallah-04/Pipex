/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:57:57 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/08 10:56:59 by amufleh          ###   ########.fr       */
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
				return NULL;
			break;
		}
		i++;
	}
	return path;
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
