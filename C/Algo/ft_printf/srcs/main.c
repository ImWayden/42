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
	i = ft_printf("premier test %%%i predf\n");
	j = printf("premier test %% predf\n");
	printf("%i %i\n", i, j);
	return 0;
}