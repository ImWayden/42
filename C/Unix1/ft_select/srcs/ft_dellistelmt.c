/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellistelmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 15:37:06 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 23:02:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			moove(t_select *list)
{
	if (list && list->pos < list->next->pos)
	{
		moove(list->next);
		list->next->pos = list->pos;
		list->next->col = list->col;
		list->next->row = list->row;
	}
}

int				delcenter(t_select **list, int argc)
{
	moove(*list);
	*list = (*list)->next;
	(*list)->curseur = 'y';
	ft_dellistelmt(&(*list)->prev);
	return (--argc);
}

void			ft_dellistelmt(t_select **list)
{
	t_select	*tmp;

	if ((tmp = *list))
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		ft_memdel((void **)&tmp->str);
		ft_memdel((void **)&tmp);
	}
}
