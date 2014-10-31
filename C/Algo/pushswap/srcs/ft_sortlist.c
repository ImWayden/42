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

/*static int		listlen(t_lex *list)
{
	int			i;
	t_lex		*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		if ((tmp = tmp->next) == list)
			break;
	}
	return (i);
}*/

int				ft_issort(t_lex *lex)
{
	t_lex		*tmp;

	tmp = lex;
	while (tmp)
	{
		if (tmp->next == lex)
			break;
		if (tmp->nbr <= tmp->next->nbr)
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

	l_b = NULL;
	l_a = *list;
	while (!ft_issort(l_a))
	{
		if (l_a->prev->nbr < l_a->nbr && l_a->prev->nbr < l_a->next->nbr)
		{
			if (l_b && l_b->prev->nbr > l_b->nbr)
				ft_rrr(&l_a, &l_b);
			else
				ft_rrr(&l_a, NULL);
		}
		else if (l_a->nbr > l_a->next->nbr)
		{
			if (l_a->nbr > l_a->prev->nbr)
			{
				if (l_b && l_b->nbr < l_b->prev->nbr)
					ft_r_r(&l_a, &l_b);
				else
					ft_r_r(&l_a, NULL);
			}
			else 
			{
				if (l_b && l_b->nbr < l_b->next->nbr)
					ft_ss(l_a, l_b);
				else
					ft_ss(l_a, NULL);
			}
		}
		else
		{
			if (l_b && l_b->prev->nbr > l_b->nbr)
				ft_rrr(NULL, &l_b);
			if (l_b && l_b->nbr < l_b->prev->nbr)
				ft_r_r(NULL, &l_b);
			if (l_b && l_b->nbr < l_b->next->nbr)
				ft_ss(l_a, l_b);
		}
		if (ft_issort(l_a))
			break;
		if (l_b && l_b->nbr > l_a->nbr)
			ft_p(&l_b, &l_a, 'a');
		else
			ft_p(&l_a, &l_b, 'b');
		//if (l_b && l_b->nbr < l_b->next->nbr)
		//	ft_ss(NULL, l_b);
	}
	ft_putendl(NULL);
	ft_putlist(l_a);
	ft_putlist(l_b);
}