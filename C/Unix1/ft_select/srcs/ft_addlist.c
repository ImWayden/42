/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:41:15 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 21:42:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select			*ft_addlist(t_select *list, char *str, int pos)
{
	t_select		*tmp;

	tmp = ft_listnew(str, pos);
	if (!list)
		return (tmp);
	else
	{
		tmp->prev = list->prev;
		list->prev->next = tmp;
		tmp->next = list;
		list->prev = tmp;
	}
	return (list);
}
