/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 14:00:48 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 15:10:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int		ft_less(int a, int b)
{
	return ((a < b) ? 1 : 0);
}

static int		ft_more(int a, int b)
{
	return ((a > b) ? 1 : 0);
}

int				ft_issort(t_lex *lex, int (*f)(int, int))
{
	t_lex		*tmp;

	tmp = lex;
	while (tmp)
	{
		if (tmp->next == lex)
			break ;
		if (tmp->nbr == tmp->next->nbr || f(tmp->nbr, tmp->next->nbr))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void			ft_sortlist(t_lex **list)
{
	t_lex		*l_b;
	t_lex		*l_a;
	int			i;

	l_b = NULL;
	l_a = *list;
	i = 0;
	while (42)
	{
		if (!(i = ft_issort(l_a, ft_less)))
			i = ft_sort(&l_a, &l_b, ft_more, ft_less);
		if (l_b && l_b != l_b->next)
			ft_sort(&l_b, &l_a, ft_less, ft_more);
		if (!l_b && i)
			break ;
		if (i)
			ft_p(&l_b, &l_a, 'a');
		else
			ft_p(&l_a, &l_b, 'b');
		if (l_a->flag)
			ft_debug(l_a, l_b);
	}
			ft_debug(l_a, l_b);
	if (!l_a->flag)
		ft_putendl(NULL);
}
