#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int ac, char **av)
{
	int		fd[2];
	char	buf[50];
	pid_t	pid;
	int		fd_out;

	(void)ac;
	fd_out = 0;
	pid = 0;
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid > 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		printf("%s", av[1]);
		close(fd[1]);
		//wait(NULL);
		return 0;
	}
	else if (pid == 0)
	{
		close(fd[1]);
		fd_out = open("test_dup2_pipe_fork.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd_out == -1)
			return (perror("fd_out"), 1);
		dup2(fd[0], 0);
		read(fd[0], buf, 4);
		write(fd_out, buf, 4);
		/*{
			perror("read");
			return (1);
		}*/
		//close(fd_out);
		close (fd[0]);
	}
}
