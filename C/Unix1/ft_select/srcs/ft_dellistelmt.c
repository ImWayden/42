/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellistelmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 15:37:06 by msarr             #+#    #+#             */
/*   Updated: 2014/05/02 15:37:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_selectlist		*ft_dellistelmt(t_selectlist **list, char *str)
{
	t_selectlist	*tmp;

	if (list && *list)
	{
		tmp = *list;
		while (tmp && ft_strcmp(tmp->str, str))
			tmp = tmp->next;
		if (tmp)
		{
			if (ft_selectlistlen(*list) == 1)
				*list = NULL;
			if (list && *list && !ft_strcmp((*list)->str, str))
				*list = (*list)->next;
			if (tmp->next)
			{
				tmp->next->curseur = 'y';
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
			}
			ft_memdel((void **)&tmp);
		}
	}
	return (*list);
}
