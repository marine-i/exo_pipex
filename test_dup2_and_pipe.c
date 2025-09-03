#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd[2];
	char	buf[50];
	int		n;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	if (dup2(fd[1], 1) == -1)
	{
		perror("dup2");
		return (1);
	}
	write(1, "Ceci est un autre test \n", 24);
	close (fd[1]);
	read(fd[0], buf, 24);
	write(STDERR_FILENO, buf, 24);
	/*
	ou au lieu de la sortie erreur , on peut dup la sortie du terminal avec dup_terminal = dup(1 // ou STDOUT_FILENO)
	*/

	close(fd[0]);
}
