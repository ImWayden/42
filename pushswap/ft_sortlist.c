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

t_list		*ft_sortlist(t_list **lista)
{
		if ((*lista)->i > (*lista)->next->i)
			ft_s(*lista);
		if (ft_listlen(*lista) == 2)
			return (*lista);
		else if (ft_listlen(*lista) == 3)
		{
			if ((*lista)->next->next->i < (*lista)->i)
				ft_rr(lista);
			else
			{
				ft_s(*lista);
				ft_r(*lista);
			}
			return (*lista);
		}
		return (*lista);
}
