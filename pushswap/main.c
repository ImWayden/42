/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 17:02:19 by msarr             #+#    #+#             */
/*   Updated: 2013/12/24 17:02:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ft_ismin(t_list *list)
{
		int		first;
		t_list	*tmp;

		first = list->i;
		tmp = list->next;
		while (tmp)
	    {
			if (first > tmp->i)
			return (0);
			tmp = tmp->next;
		}
		return (1);
}

static t_list		*ft_pushswapbis(t_list **lista, t_list **listb)
{
	while (*lista)
	{
		while (!ft_ismin(*lista))
		{
			ft_r( *lista);
			write(1, "a ", 2);
		}
		if (ft_ismin(*lista))
		{
			ft_p(lista, listb);
			write(1, "b ", 2);
		}
	}
	while (*listb)
	{
		ft_p(listb, lista);
		if (*listb)
			write(1, "a ", 2);
		else
			write(1, "a", 1);
	}
	write(1, "\n", 1);
	return (*lista);
}

int main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;
	int		j;
	if (argc > 1)
	{
		lista = NULL;
		j = 1;
		while (j < argc)
		{
			lista = ft_addlist(lista, ft_atoi(argv[j]));
			j++;
		}
	}
	lista = ft_pushswapbis(&lista, &listb);
	return 0;
}