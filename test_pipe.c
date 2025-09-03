/*#include <unistd.h>
//#include <sys/types.h>
#include <stdio.h>


int	main()
{
	char	buf[50];
	int		fd[2];
	int		n;

	pipe(fd);
	write(fd[1], "abc\n", 4);
	n = read(fd[0], buf, 1);
	buf[n] = '\0';
	write(1, buf, 1);
}
*/

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		n;
	int		fd[2];
	char	buf[50];
	int		fd_pipe;

	fd_pipe = pipe(fd); // créer fd[0] = lecture; fd[1] = écriture
	if (fd_pipe == -1)
	{
		perror("pipe");
		return (1);
	}
	if (write(fd[1], "Bonjour42", 9) == -1)
	{
		perror("write");
		return (1);
	}
	close(fd[1]);

	while (read(fd[0], buf, 1) > 0)
	{
		write(1, buf, 1);
	}
	//n = read(fd[0], buf, 4);
	if (read(fd[0], buf, 1) == -1)
	{
		perror("read");
		return (1);
	}
	//buf[n] = '\0';
	write(1, "\n", 1);
	/*n = read(fd[0], buf, 5);
	if (n == -1)
	{
		perror("read");
		return (1);
	}*/


	/*buf[n] = '\0';
	write(1, buf, n);
	write(1, "\n", 1);*/
	//close(fd[1]);

	/*n = read(fd[0], buf, 5);
	write(1, buf, n);
	write(1, "\n", 1);*/
	if (n == 0)
	{
		printf("EOF atteint\n");
	}

	//close(fd[0]);
}
