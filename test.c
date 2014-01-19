#include <stdio.h>

int main(int argc, char const *argv[])
{
	int	i;

	i = 1;
	write(1, "a", 1);
	while (i);
	{
		write(1, "a", 1);
		i++;
	}
	return 0;
}