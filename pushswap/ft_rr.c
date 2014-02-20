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

void		ft_rr(t_list **list)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp1;

	if (ft_listlen(*list) > 1)
	{
		write(1, "rr", 2);
		tmp = *list;
		while (tmp->next)
		{	tmp1 = tmp;
			tmp = tmp->next;
		}
		i = tmp->i;
		tmp1->next = NULL;
		free (tmp);
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->i = i;
		tmp->next = *list;
		*list = tmp;
	}
}
