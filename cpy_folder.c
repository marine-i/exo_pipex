#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd_out;
	int		n;
	char	buff[50];

	n = 0;
	fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
		write(1, "oups\n", 5);
	fd_out = open("txt_out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while ((n = read(fd, buff, 50)) > 0)
	{
		write(fd_out, buff, n);
	}
	close(fd);
	close(fd_out);
}
