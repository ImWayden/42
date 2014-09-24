#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char    *s;
	int     status;
	int     fd;

	fd = open(argv[argc - 1], O_RDONLY);
	while ((status = get_next_line(fd, &s)) > 0)
	{
		printf("[%s]\n", s);
		free(s);
		get_next_line(0, &s);
		printf("[%s]\n", s);
		free(s);
	}
	printf("[%d]\n", status);
	return (0);
}
