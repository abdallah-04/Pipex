/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:11:00 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/08 16:09:48 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	do_command_two(t_command_info command, char **argv, int *fd_pipe)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_WRONLY, 0644);
	if (fd_outfile == -1)
		clean_and_exit(command, fd_pipe, -1);
	if (dup2(fd_pipe[0], 0) == -1)
		clean_and_exit(command, fd_pipe, fd_outfile);
	if (dup2(fd_outfile, 1) == -1)
		clean_and_exit(command, fd_pipe, fd_outfile);
	close(fd_outfile);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	command.command_args = ft_split(argv[3], ' ');
	if (!command.command_args)
		clean_and_exit(command, fd_pipe, fd_outfile);
	command.absolute_path = get_cmd_path(&command);
	if (!command.absolute_path)
		clean_and_exit(command, fd_pipe, fd_outfile);
	execve(command.absolute_path, command.command_args, command.env);
	perror("Error");
	clean_and_exit(command, fd_pipe, fd_outfile);
}

static void	do_command_one(t_command_info command, char **argv, int *fd_pipe)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		clean_and_exit(command, fd_pipe, fd_infile);
	if (dup2(fd_infile, 0) == -1)
		clean_and_exit(command, fd_pipe, fd_infile);
	if (dup2(fd_pipe[1], 1) == -1)
		clean_and_exit(command, fd_pipe, fd_infile);
	close(fd_infile);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	command.command_args = ft_split(argv[2], ' ');
	if (!command.command_args)
		clean_and_exit(command, fd_pipe, fd_infile);
	command.absolute_path = get_cmd_path(&command);
	if (!command.absolute_path)
		clean_and_exit(command, fd_pipe, fd_infile);
	execve(command.absolute_path, command.command_args, command.env);
	perror("Error");
	clean_and_exit(command, fd_pipe, fd_infile);
}

static void	do_commands(char **argv, char **env, int *fd_pipe, int cmd_num)
{
	t_command_info command;

	ft_bzero(&command, sizeof(t_command_info));
	init_command(&command, env);
	if (cmd_num == 1)
		do_command_one(command, argv, fd_pipe);
	else
		do_command_two(command, argv, fd_pipe); 
	exit(1); 
}

int main(int argc, char **argv, char **env)
{
	int	fd_pipe[2];
	int	fork1_id;
	int	fork2_id;

	if (argc != 5)
		return (0);
	if (pipe(fd_pipe) == -1)
		handel_syscall(fd_pipe);
	fork1_id = fork();
	if (fork1_id == -1) 
		handel_syscall(fd_pipe);
	if (fork1_id == 0)
		do_commands(argv, env, fd_pipe, 1);
	fork2_id = fork();
	if (fork2_id == -1) 
		handel_syscall(fd_pipe);
	if (fork2_id== 0)
		do_commands(argv, env, fd_pipe, 2);
	ignore_parents(fd_pipe);
    return (0);
}