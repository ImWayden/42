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

	if ((lista && *lista && get_flag(*lista))
		|| (listb && *listb && get_flag(*listb)))
		write(1, " ", 1);
	a = ft_rr(lista);
	b = ft_rr(listb);
	if (a && !b)
		write(1, "a", 1);
	else if (!a && b)
		write(1, "b", 1);
}
