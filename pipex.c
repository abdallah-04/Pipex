/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:11:00 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/07 15:21:59 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	do_command_one(command_info command, char **argv, int *fd_pipe)
{
	int fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		return (0);
	dup2(fd_infile, 0);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	command.command_args = ft_split(argv[2], ' ');
	command.absolute_path = get_cmd_path(&command);
	execve(command.absolute_path, command.command_args, command.env);
	return (1);
}

int do_command_tow(command_info command, char **argv, int *fd_pipe)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_WRONLY, 0644);
	if (fd_outfile == -1)
		return (0);
	dup2(fd_pipe[0], 0);
	dup2(fd_outfile, 1);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	command.command_args = ft_split(argv[3], ' ');
	command.absolute_path = get_cmd_path(&command);
	execve(command.absolute_path, command.command_args, command.env);
    return (0);
}

void set_up(command_info command, char **env)
{
	command.env = env;
	command.path = get_$path(command.env);
	command.command_folders = ft_split(command.path, ':');
}

int main(int argc, char **argv, char **env)
{
	int	fd_pipe[2];
	int	pipe_res;
	int	fork_id;
	command_info command;

	if (argc != 5)
		return (0);
	pipe_res = pipe(fd_pipe);
	if (pipe_res == -1)
		return (perror("pipe"), 1);
	fork_id = fork();
	if (fork_id == -1)
		return (perror("fork"), 1);
	set_up(command, env);
	if (fork_id == 0)
	{
		if (!do_command_one(command, argv, fd_pipe))
			return (0);
	}
	else
	{
		if (!do_command_tow(command, argv, fd_pipe))
			return (0);
	}
	return (0);
}
