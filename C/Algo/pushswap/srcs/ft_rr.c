/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:59:29 by msarr             #+#    #+#             */
/*   Updated: 2013/12/24 16:59:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ft_rr(t_lex **list)
{
	if (list && *list && *list != (*list)->next)
	{
		*list = (*list)->prev;
		write(1, "rr", 2);
		return (1);
	}
	return (0);
}

void		ft_rrr(t_lex **lista, t_lex **listb)
{	
	int		a;
	int		b;

	a = ft_rr(lista);
	b = ft_rr(listb);
	if (a && !b)
		write(1, "a ", 2);
	else if (!a && b)
		write(1, "b ", 2);
	else
	{
		a = 8;
		write(1, &a, 1);
		write(1, " ", 1);
	}
}