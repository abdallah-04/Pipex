/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:58:16 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/07 15:10:29 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct s_command_info {
	char	**command_folders;
	char	*path;
	char	**command_args;
	char	*absolute_path;
	char	**env;
} command_info;

char	*get_$path(char **env);
char	*get_cmd_path(command_info *info);
