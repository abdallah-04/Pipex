#include "pipex.h"

void    handel_syscall(int *fd_pipe, int flag)
{
	if (flag)
		close_fds(fd_pipe, 1);
    perror("Error"); 
    exit(1);
}

void    ignore_parents(int *fd_pipe)
{
	close_fds(fd_pipe, 1);
	wait(NULL);
	wait(NULL);
}