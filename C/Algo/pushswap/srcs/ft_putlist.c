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
