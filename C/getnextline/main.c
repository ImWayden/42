#include <stdio.h>
 #include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line);

int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line = NULL;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open("get_next_line.h", O_RDONLY);
	fd2 = open("get_next_line.c", O_RDONLY);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		close(fd2);
		return (-1);
	}
	while (get_next_line(fd, &line) >= 0)
	{
		write(0, line, strlen(line));
		write(0, &n, 1);					// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
		free(line);							// vous inquietez pas
	}
	close(fd);
	close(fd2);
	return (0);
}