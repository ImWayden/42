#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_putstr(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);

}

typedef struct		s_list
{
	char *str;
	struct s_list *next;
}					t_list;

t_list		*ft_add_list(t_list *list, char *str)
{
	t_list  *tmp;
	
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->str = strdup(str);
	tmp->next = list;
	return (tmp);
}

int main()
{
	int fd;
	char	*str;

	fd = 0;
	if (fd != -1)
	{
		get_next_line(fd, &str);
		ft_putstr(str);
		get_next_line(fd, &str);
		ft_putstr(str);
	}
	else
		printf("ca set mal passee\n");
	close(fd);
	return 0;
}