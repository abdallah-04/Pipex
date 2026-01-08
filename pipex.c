/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:11:00 by amufleh           #+#    #+#             */
/*   Updated: 2026/01/08 10:57:13 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	perror("Error");
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
	exit(1);
}

int do_command_two(t_command_info command, char **argv, int *fd_pipe)
{
	int fd_outfile;

	fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
		clean_and_exit(command, NULL, -1);
	command.absolute_path = get_cmd_path(&command);
	if (!command.absolute_path)
		clean_and_exit(command, NULL, -1);
	execve(command.absolute_path, command.command_args, command.env);
	perror("execve");
	clean_and_exit(command, NULL, -1);
	return (1);
}

int do_command_one(t_command_info command, char **argv, int *fd_pipe)
{
	int fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		clean_and_exit(command, fd_pipe, -1);
	if (dup2(fd_infile, 0) == -1)
		clean_and_exit(command, fd_pipe, fd_infile);
	if (dup2(fd_pipe[1], 1) == -1)
		clean_and_exit(command, fd_pipe, fd_infile);
	close(fd_infile);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	command.command_args = ft_split(argv[2], ' ');
	if (!command.command_args)
		clean_and_exit(command, NULL, -1);
	command.absolute_path = get_cmd_path(&command);
	if (!command.absolute_path)
		clean_and_exit(command, NULL, -1);
	execve(command.absolute_path, command.command_args, command.env);
	perror("execve");
	clean_and_exit(command, NULL, -1);
	return (1);
}

void	set_up(t_command_info command, char **env)
{
	command.env = env;
	command.path = get_path(command.env);
	command.command_folders = ft_split(command.path, ':');
}
void init_command(t_command_info command, char **env)
{
	command.command_args = NULL;
	command.command_folders = NULL;
	command.absolute_path = NULL;
	command.env = env;
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
	command.command_args = NULL;
	command.command_folders = NULL;
	command.absolute_path = NULL;
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
