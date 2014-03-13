/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/13 14:07:49 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemlist		*ft_lemlistnew(char *str)
{
	t_lemlist	*tmp;

	tmp = (t_lemlist *)malloc(sizeof(t_lemlist));
	if (tmp)
	{
		tmp->str = ft_strdup(str);
		tmp->next = NULL;
	}
	return (tmp);
}

t_lemlist		*ft_addlemlist(t_lemlist *list, char *str)
{
	t_lemlist	*tmp;

	tmp = ft_lemlistnew(str);
	if (list)
		tmp->next = list;
	return (tmp);
}

int				ft_lemlistlen(t_lemlist *list, char * str, t_lem *lem)
{
	int			i;

	i = 0;
	while (list && list->str)
	{
		if (ft_strcmp(list->str, str) && ft_strcmp(list->str, lem->start))
			i++;
		if (!ft_strcmp(list->str, lem->end))
			return (-1);
		list = list->next;
	}
	return (i);
}

void			dellist(t_lemlist **list)
{
	t_lemlist	*tmp;

	
	while (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
			ft_memdel((void **)&(tmp->str));
		if (tmp)
		{
			if (tmp->str)
			ft_memdel((void **)&(tmp->str));
			//ft_memdel((void **)&tmp);
			tmp = NULL;
		}
		*list = (*list)->next;
	}
}

void			delroomlist(t_lemroom *room, t_lem *lem)
{
	if (room)
		(lem->tab)[hashcode(room->name)] = NULL;
}
