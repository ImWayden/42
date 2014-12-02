/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/02 02:29:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*new_room(char *str, int x, int y)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	if (room)
	{
		room->name = ft_strdup(str);
		room->dist = 100000000;
		room->lem = 0;
		room->step = 0;
		room->x = x;
		room->y = y;
		room->z = 0;
		room->lst = NULL;
	}
	return (room);
}

int			get_room(char *str, t_lem *lem, int flag)
{
	char	**tab;

	if ((tab = ft_strsplit(str, ' ')) && tab[0])
	{
		lem->tab[hash(tab[0])] = new_room(tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
		if (flag == 1)
			lem->start = lem->tab[hash(tab[0])];
		if (flag == 2)
			lem->end = lem->tab[hash(tab[0])];
		return (1);
	}
	return (0);
}

int			get_door(t_lem *lem, int flag)
{
	char	*str;

	str = NULL;
	get_next_line(0, &str);
	ft_putendl(str);
	return (get_room(str, lem, flag));
}