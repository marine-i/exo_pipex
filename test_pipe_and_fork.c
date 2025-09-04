#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	int		fd[2];
	int		fd_pipe;
	__pid_t	pid;
	char	buf[50];

	fd_pipe = pipe(fd);
	if (fd_pipe == -1)
	{
		perror("pipe");
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("pid");
		return (1);
	}

	if (pid > 0)
	{
		close (fd[0]);
		write(fd[1], "test", 4);
		close (fd[1]);
		wait(NULL);
		// attend le fils sinon shell peut afficher le prompt avant le reésultat du read
		return (0);
	}
	if (pid == 0)
	{
		close (fd[1]);
		read(fd[0], buf, 4);
		write(1, buf, 4);
		write(1, "\n", 1);
		close(fd[0]);
	}

}
