/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:59:59 by msarr             #+#    #+#             */
/*   Updated: 2014/03/19 14:00:02 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			connect(t_lemroom *room, t_lem *lem)
{
	int			i;
	t_lemroom	*room1;

	if (room && room->dist == 10000)
	{
		i = 0;
		while (room && room->tab && room->tab[i])
		{
			room1 = (room->tab[i]);
			if (lem->tab[hash(room1->name)])
			{
				room->tab[i] = lem->tab[hash(room1->name)];
				lem->tab[hash(room1->name)] = NULL;
				delroom(&room1);
				i++;
			}
			else
				moove(room->tab, i);
		}
	}
}

void				weight(t_lemroom *room, t_lem *lem)
{
	int				i;

	i = 0;
	while (room && room->tab && (room->tab)[i])
	{
		weight((room->tab)[i], lem);
		i++;
	}
	if (room && room->tab && room->tab[0])
	{
		sort(room->tab);
		room->dist = ((room->tab)[0])->dist + 1;
	}
}

t_lemroom		**allconnect(t_lemroom **room, t_lem *lem)
{
	int			i;
	t_lemroom	**tab;
	t_lemroom   **tmp;

	i = 0;
	tab = NULL;
	while (room && room[i])
	{
		connect(room[i], lem);
		tmp = room[i]->tab;
		if (tmp && tmp[0] && ft_strcmp(tmp[0]->name, lem->end))
			tab = merge(&tab, tmp);
		i++;
	}
	return (tab);
}
