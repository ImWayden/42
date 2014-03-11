/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:42:44 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 15:42:47 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemroom		*newroom(char *str, t_lem *lem)
{
	t_lemroom	*room;
	t_lemlist	*list;
	int			i;

	list = (lem->tab)[hashcode(str)];
	list = is(list, lem);
	i = ft_lemlistlen(list, str, lem);
	room = allocroom(str);
	if (room && i > 0)
	{
		room->tab = alloctabroom(i);
		if (!room->tab)
			room->dist = -1;
		else
			listtotab(list, lem, room, i);
	}
	else if (i == -1)
	{
		room->tab = alloctabroom(1);
		room->tab[0] = allocroom(lem->end);
		room->dist = 1;
	}
	return (room);
}

t_lemroom		*newendroom(char *str, t_lem *lem)
{
	t_lemroom	*room;
	t_lemlist	*list;
	int			i;

	list = (lem->tab)[hashcode(str)];
	if (!list)
		return (NULL);
	i = ft_lemlistlen(list, str, lem);
	room = allocroom(str);
	if (room && i != -1)
	{
		room->tab = alloctabroom(i);
		if (!room->tab)
			room->dist = -1;
		else
			listtotab(list, lem, room, i);
	}
	return (room);
}

t_lemroom		*connect(t_lemroom *room, t_lem *lem)
{
	int			i;

	if (room && room->tab && room->dist == 10000)
	{
		i = 0;
		while (room->tab && room->tab[i])
		{
			room->tab[i] = newroom(((room->tab)[i])->name, lem);
			i++;
		}
		i = 0;
		while (room->tab && room->tab[i])
		{
			if ((room->tab[i])->dist == 10000)
				room->tab[i] = connect(room->tab[i], lem);
			i++;
		}
		sort(room->tab);
		if (room && room->tab && room->tab[0])
			room->dist = (room->tab[0])->dist + 1;
		else
			room->dist = -1;
	}
	return (room);
}
