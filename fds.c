#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "trinity.h"

#define MAX_PIPE_FDS 10
unsigned int pipe_fds[MAX_PIPE_FDS*2];

unsigned int fds[MAX_FDS/2];
unsigned int fd_idx = 0;

unsigned int fds_left_to_create = MAX_FDS;

void open_pipes(void)
{
	int pipes[2];
	unsigned int i;

	for (i = 0; i < MAX_PIPE_FDS; i++) {
		if (pipe(pipes) < 0) {
			perror("pipe fail.\n");
			exit(EXIT_FAILURE);
		}
		pipe_fds[i] = pipes[0];
		pipe_fds[i+1] = pipes[1];

		output("fd[%d] = pipe\n", pipe_fds[i]);
		output("fd[%d] = pipe\n", pipe_fds[i+1]);
	}
}

void setup_fds(void)
{
	//open_pipes();
	open_sockets();
	open_files();
}


int get_random_fd(void)
{
	unsigned int i;
	unsigned int fd = 0;

	if (do_specific_proto == 1)
		i = 1;
	else
		i = rand() % 3;

	switch (i) {
	case 0:
retry:		fd = fds[rand() % fd_idx];
		/* retry if we hit stdin/stdout/logfile */
		if (fd < fds[0])
			goto retry;
		break;

	case 1:
		fd = socket_fds[rand() % socks];
		break;

	case 2:
		fd = pipe_fds[rand() % MAX_PIPE_FDS];
		break;
	}

	return fd;
}
