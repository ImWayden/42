#include "ft_printf.h"
#include <stdio.h>

void		put(t_lex *lex)
{
	t_lex	*tmp;

	tmp = lex;
	while(tmp)
	{
		printf("%s\n", tmp->name);
		if ((tmp = tmp->next) == lex)
			break;
	}
}

int main()
{
	int	i;
	int	j;
	i = ft_printf("premier test %%c %c predf\n", 4000);
	j = printf("premier test %%c %c predf\n", 4000);
	printf("%i %i\n", i, j);
	return 0;
}