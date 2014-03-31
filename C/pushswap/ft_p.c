 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 22:00:35 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 22:00:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ft_p(t_list **list, t_list	**list1)
{
	t_list	*tmp;

	if (ft_listlen(*list) > 0)
	{
		write(1, "p", 1);
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->i = (*list)->i;
		tmp->next = NULL;
		if (*list1)
			tmp->next = *list1;
		*list1 = tmp;
		tmp = *list;
		(*list) = (*list)->next;
		free (tmp);
	}
}
