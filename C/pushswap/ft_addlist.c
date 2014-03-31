/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:53:49 by msarr             #+#    #+#             */
/*   Updated: 2013/12/24 15:53:54 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_list		*ft_addlist(t_list *list, int i)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->i = i;
	tmp->next = NULL;
	if (list == NULL)
		list = tmp;
	else
	{
		tmp1 = list;
		while (tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
	}
	return (list);
}
