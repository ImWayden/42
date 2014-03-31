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

void		ft_r(t_list *list)
{
	int		i;
	t_list	*tmp;

	if (ft_listlen(list) > 1)
	{
		tmp = list;
		i = tmp->i;
		write(1, "r", 1);
		while (tmp->next)
		{
			tmp->i = tmp->next->i;
			tmp = tmp->next;
		}
		tmp->i = i;
	}
}
