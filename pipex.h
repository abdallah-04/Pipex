/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:58:16 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/08 16:06:03 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <sys/wait.h>

typedef struct s_command_info
{
	char	**command_folders;
	char	*path;
	char	**command_args;
	char	*absolute_path;
	char	**env;
}	t_command_info;

char	*get_path(char **env);
char	*get_cmd_path(t_command_info *info);
void	clean_and_exit(t_command_info cmd, int *fd_pipe, int fd_file);
void	free_split(char **arr);
void    init_command(t_command_info *command, char **env);
void	ignore_parents(int *fd_pipe);
void	handel_syscall(int *fd_pipe);