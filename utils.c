/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:57:57 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/07 15:42:31 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (!(ft_strncmp(env[i], "PATH=", 5)))
		{
			path = ft_strdup(env[i]) + 5;
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
