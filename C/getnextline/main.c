#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char    *s;
	int     status;

	while ((status = get_next_line(0, &s)) > 0)
	{
		printf("[%s]\n", s);
		free(s);
	}
	return (0);
}
