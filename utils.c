/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:57:57 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/07 12:17:03 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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
