/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:41:15 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:41:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						ft_selectlistlen(t_selectlist *list)
{
	t_selectlist		*tmp;
	int					i;

	i = 0;
	tmp = list;
	if (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp != list)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_selectlist			*ft_addlist(t_selectlist *list, char *str)
{
	t_selectlist		*tmp;

	tmp = ft_listnew(str);
	if (!list)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		list = tmp;
	}
	else
	{
		tmp->prev = list->prev;
		list->prev->next = tmp;
		tmp->next = list;
		list->prev = tmp;
	}
	return (list);
}
