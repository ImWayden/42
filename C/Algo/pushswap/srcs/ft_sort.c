/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 16:11:08 by msarr             #+#    #+#             */
/*   Updated: 2014/11/02 16:11:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_sortb(t_lex **l_a, t_lex **l_b, int (*f)(int, int), int (*f1)(int, int))
{
	if (f((*l_a)->nbr, (*l_a)->next->nbr))
	{
		if (f((*l_a)->nbr, (*l_a)->next->next->nbr))
		{
			if (*l_b && f1((*l_b)->nbr, (*l_b)->prev->nbr))
				ft_r_r(l_a, l_b);
			else
				ft_r_r(l_a, NULL);
			if ((*l_a)->flag)
				ft_debug(*l_a, *l_b);
		}
		if (*l_b && f1((*l_b)->nbr, (*l_b)->next->nbr))
			ft_ss(*l_a, *l_b);
		else if (f((*l_a)->nbr, (*l_a)->next->nbr))
			ft_ss(*l_a, NULL);
		if ((*l_a)->flag)
			ft_debug(*l_a, *l_b);
	}
	return (1);
}

int	ft_sort(t_lex **l_a, t_lex **l_b, int (*f)(int, int), int (*f1)(int, int))
{
	ft_sortb(l_a, l_b, f, f1);
	if (f1((*l_a)->prev->nbr, (*l_a)->nbr))
	{
		if (*l_b && f((*l_b)->prev->nbr, (*l_b)->nbr))
			ft_rrr(l_a, l_b);
		else
			ft_rrr(l_a, NULL);
		if ((*l_a)->flag)
			ft_debug(*l_a, *l_b);
	}
	ft_sortb(l_a, l_b, f, f1);
	return (ft_issort(*l_a, f1));
}
