#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

// int dup2(int oldfd, int newfd);
// sert a rediriger newfd vers le meme chemin que oldfd

int	main(void)
{
	int	fd_out;

	fd_out = open("test_dup2.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd_out == -1)
	{
		perror("open");
		return (1);
	}
	if (dup2(fd_out, 1) == -1)
	{
		perror("dup2");
		return (1);
	}
	printf("ceci est un test");
	close (fd_out);
	return (0);
}
