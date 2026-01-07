/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:11:00 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/07 19:20:15 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	clean_and_exit(t_command_info cmd, int *fd_pipe, int fd_outfile)
{
	if (fd_pipe)
	{
		close(fd_pipe[0]);
		close(fd_pipe[1]);
	}
	if (fd_outfile != -1)
		close(fd_outfile);
	free_split(cmd.command_args);
	free(cmd.absolute_path);
	exit(1);
}
int	do_command_one(t_command_info command, char **argv, int *fd_pipe)
{
	int	fd_infile;
	int	dup_a;
	int	dup_b;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		return (0);
	dup_a = dup2(fd_infile, 0);
	dup_b = dup2(fd_pipe[1], 1);
	if (dup_a == -1 || dup_b == -1)
	{
		perror("dup2");
		clean_and_exit(command, fd_pipe, fd_infile);
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	command.command_args = ft_split(argv[3], ' ');
	if (!command.command_args)
	{
		perror("ft_split");
		exit(1);
	}
	command.absolute_path = get_cmd_path(&command);
	if (!command.absolute_path)
	{
		perror("command not found");
		free_split(command.command_args);
		clean_and_exit(command, fd_pipe, fd_infile);
	}
	execve(command.absolute_path, command.command_args, command.env);
	close(fd_infile);
	return (1);
}

int	do_command_two(t_command_info command, char **argv, int *fd_pipe)
{
	int	fd_outfile;
	int	dup_a;
	int	dup_b;
	int	execve_res;

	fd_outfile = open(argv[4], O_CREAT | O_WRONLY, 0644);
	if (fd_outfile == -1)
		return (0);
	dup_a = dup2(fd_pipe[0], 0);
	dup_b = dup2(fd_outfile, 1);
	if (dup_a == -1 || dup_b == -1)
	{
		perror("dup2");
		close(fd_outfile);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		exit(0);
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	command.command_args = ft_split(argv[3], ' ');
	command.absolute_path = get_cmd_path(&command);
	// if (!command.absolute_path || !command.command_args)
	// {

	// }
	execve_res =  execve(command.absolute_path, command.command_args, command.env);
	// if (execve_res == -1)
	// {

	// }
	close(fd_outfile);
	return (0);
}

void	set_up(t_command_info command, char **env)
{
	command.env = env;
	command.path = get_path(command.env);
	command.command_folders = ft_split(command.path, ':');
}

int	main(int argc, char **argv, char **env)
{
	t_command_info	command;
	int				fd_pipe[2];
	int				pipe_res;
	int				fork_id;

	if (argc != 5)
		return (0);
	pipe_res = pipe(fd_pipe);
	if (pipe_res == -1)
		return (perror("pipe"), 1);
	fork_id = fork();
	if (fork_id == -1)
		return (perror("fork"), 1);
	//set_up(command, env);
	command.env = env;
	command.path = get_path(command.env);
	command.command_folders = ft_split(command.path, ':');
	if (fork_id == 0)
	{
		if (!do_command_one(command, argv, fd_pipe))
			return (0);
	}
	else
	{
		if (!do_command_two(command, argv, fd_pipe))
			return (0);
	}
	return (0);
}
