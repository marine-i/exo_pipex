#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd_out;
	int	value_dup;

	value_dup = 0;
	fd_out = open("redirection_out.txt", O_WRONLY);
	value_dup = dup2(fd_out, 1);
	//write(1, "hello\n", 6);
	write(1, "A\n", 2);
	write(fd_out, "B\n", 2);
	printf("%d\n", value_dup);

}