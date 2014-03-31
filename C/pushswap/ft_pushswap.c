/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 20:17:53 by msarr             #+#    #+#             */
/*   Updated: 2013/12/27 20:17:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_list		*ft_pushswap(t_list **lista)
{
	int		i;
	t_list	*listb;

	if (ft_issort(*lista) == 1 || ft_issort(*lista) == -1)
		return (*lista);
	else if (ft_listlen(*lista) == 2 || ft_listlen(*lista) == 3)
		return (ft_sortlist(lista));
	else
	{
		listb = NULL;
		i = ft_listlen(*lista) / 2;
		while (i)
		{
			ft_p(lista, &listb);
			i--;
		}
		ft_putlist(*lista);
		ft_putlist(listb);
		*lista = ft_pushswap(lista);
		ft_putlist(*lista);
		listb = ft_pushswap(&listb);
		if (listb)
			ft_putlist(listb);
		return (ft_merge(lista, &listb));
	}
}