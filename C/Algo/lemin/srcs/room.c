/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/08 05:09:50 by msarr            ###   ########.fr       */
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
		room->s = 0;
		room->x = x;
		room->y = y;
		room->z = 0;
		room->lst = NULL;
	}
	return (room);
}

int			get_room(char **tab, t_lem *lem, int flag)
{
	lem->tab[hash(tab[0])] = new_room(tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
	if (flag == 1)
		lem->start = lem->tab[hash(tab[0])];
	if (flag == 2)
		lem->end = lem->tab[hash(tab[0])];
	return (1);
}

t_lex		*get_door(t_lem *lem, t_lex *l, int flag)
{
	char	**tab;

	tab = ft_strsplit(l->str, ' ');
	if (tab && *tab && tab[1] && tab[2])
	{
		if (is_num(tab[1]) && is_num(tab[2]))
		{
			get_room(tab, lem, flag);
			return (l->next);
		}
	}
	return (NULL);
}

int			sort(t_room **r)
{
	t_link	*l;
	int		i;

	i = 0;
	while (i < 1000)
	{
		if (r[i])
		{
			l = r[i]->lst;
			r[i]->lst = sort_link(l);
		}
		i++;
	}
	return (1);
}
