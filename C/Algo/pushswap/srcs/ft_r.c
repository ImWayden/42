/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 16:42:35 by msarr             #+#    #+#             */
/*   Updated: 2013/12/24 16:42:37 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ft_r(t_lex **list)
{
	if (list && *list && *list != (*list)->next)
	{
		*list = (*list)->next;
		write(1, "r", 1);
		return (1);
	}
	return (0);
}

void		ft_r_r(t_lex **lista, t_lex **listb)
{
	int		a;
	int		b;

	if ((lista && *lista && get_flag(*lista))
		|| (listb && *listb && get_flag(*listb)))
		write(1, " ", 1);
	a = ft_r(lista);
	b = ft_r(listb);
	if (a && !b)
		write(1, "a", 1);
	else if (!a && b)
		write(1, "b", 1);
}
