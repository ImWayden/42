/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:40:26 by msarr             #+#    #+#             */
/*   Updated: 2013/12/27 14:40:29 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_issort(t_list *list)
{
	while (list)
	{
		while (list->next)
		{
			if (list->i < list->next->i)
				list = list->next;
			else
				return (0);
		}
		return (1);

	}
	return (-1);
}
