/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 19:20:23 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 19:20:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ft_s(t_lex *list)
{
	int		i;

	if (list && list->next != list)
	{
		i = list->nbr;
		list->nbr = list->next->nbr;
		list->next->nbr = i;
		write(1, "s", 1);
		return (1);
	}
	return (0);
}

void		ft_ss(t_lex *lista, t_lex *listb)
{	
	int		a;
	int		b;

	a = ft_s(lista);
	b = ft_s(listb);
	if (a && !b)
		write(1, "a", 1);
	if (!a && b)
		write(1, "b", 1);
}