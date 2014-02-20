/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:40:57 by msarr             #+#    #+#             */
/*   Updated: 2013/12/27 14:41:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_list		*ft_merge(t_list **lista, t_list **listb)
{
	int i;

	i = 0;
	while (*listb && *lista)
	{
		if ((*lista)->i > (*listb)->i)
			ft_p(listb, lista);
		else
		{
			i++;
			ft_r(*lista);
		}
		if (i > ft_listlen(*lista))
		{
			ft_p(listb, lista);
			ft_rr(lista);
			i = 0;
		}
	}
	while (i--)
		ft_rr(lista);
	return (*lista);
}