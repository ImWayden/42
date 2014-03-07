/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/07 01:38:28 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemroom		*newroom(char *str)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		if (str)
			room->name = ft_strdup(str);
		else
			room->name = NULL;
		room->tab  = NULL;
	}
	return (room);
}

int			tabroomlen(t_lemroom **tabroom)
{
	int		i;

	i = 0;
	while (tabroom && tabroom[i])
		i++;
	return (i);
}

void		tabroomcpy(t_lemroom **tabroom, t_lemroom **tabroom1, t_lemroom **tabroom2)
{
	int		i;

	i = 0;
	while (tabroom[i])
	{
		tabroom2[i] = tabroom[i];
		i++;
	}
	while (tabroom1[i])
	{
		tabroom2[i] = tabroom1[i];
		i++;
	}
}

t_lemroom		**recupfirstroom(t_lemroom *room, t_lem *lem)
{
	t_lemlist	*list;
	int			i;

	i = 0;
	list = lem->tab[hashcode(room->name)];
	if (is(list, lem))
	{
		room->tab = (t_lemroom **)malloc(sizeof(t_lemroom *));
		(room->tab)[0] = newroom(lem->end);
		return (NULL);
	}
	i = ft_lemlistlen(list);
	room->tab = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + 1));
	(room->tab)[i] = NULL;	
	i = 0;
	while (list && room)
	{
		if (list->str && ft_strcmp(list->str, lem->start) && ft_strcmp(list->str, room->name))
		{
			(room->tab)[i] = newroom(list->str);
			i++;
		} 
		list = list->next;
	}
	lem->tab[hashcode(room->name)] = NULL;
	return (room->tab);
}

t_lemroom	**merge(t_lemroom **tabroom, t_lemroom **tabroom1)
{
	int			i;
	int			j;
	t_lemroom	**tabroom2;

	if(!tabroom1)
		return (tabroom);
	if(!tabroom)
		return (tabroom1);
	i = tabroomlen(tabroom);
	j = tabroomlen(tabroom1);
	tabroom2 = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + j + 1));
	tabroom2[i + j] = NULL;
	tabroomcpy(tabroom, tabroom1, tabroom2);
	return (tabroom2);
}

t_lemroom	**recupnextroom(t_lemroom **tabroom, t_lem *lem)
{
	t_lemroom	**tabroom1 = NULL;
	int	i;

	i = 0;
	while (tabroom && tabroom[i])
	{
		tabroom1 = merge(tabroom1, recupfirstroom(tabroom[i], lem));
		i++;
	}
	i = 0;
	while (tabroom[i])
	{
		if (ft_strcmp((tabroom[i])->name, lem->end))
		lem->tab[hashcode((tabroom[i])->name)] = NULL;
		i++;
	}
	return (tabroom1);
}