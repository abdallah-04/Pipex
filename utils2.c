#include "pipex.h"

void	close_fds(int *fd_pipe, int fd_file)
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
}

void	handel_syscall(int *fd_pipe, int flag)
{
	if (flag)
		close_fds(fd_pipe, 1);
	perror("Error"); 
	exit(1);
}

void	ignore_parents(int *fd_pipe)
{
	close_fds(fd_pipe, 1);
	wait(NULL);
	wait(NULL);
}