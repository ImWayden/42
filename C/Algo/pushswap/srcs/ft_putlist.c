/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:59 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:57:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_putlist(t_lex *list)
{
	t_lex	*tmp;
	
	tmp = list;
	while (tmp)
	{
		ft_putnbr(tmp->nbr);
		ft_putstr(" ");
		if ((tmp = tmp->next) == list)
			break;
	}
	ft_putendl(NULL);
}

void	ft_debug(t_lex *l_a, t_lex *l_b)
{
	int	i;

	i = 8;
	write(1, &i, 1);
	write(1, "\n", 1);
	ft_putstr ("l_a : ");
	ft_putlist(l_a);
	ft_putstr ("l_b : ");
	ft_putlist(l_b);
}
