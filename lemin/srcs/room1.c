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

void		tabroomcpy(t_lemroom **tab, t_lemroom **tab1, t_lemroom **tab2)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		tab2[i] = tab[i];
		i++;
	}
	while (tab1 && tab1[i])
	{
		tab2[i] = tab1[i];
		i++;
	}
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
	tabroom2 = alloctabroom(i + j);
	tabroomcpy(tabroom, tabroom1, tabroom2);
	return (tabroom2);
}

static int		filter(t_lemroom *room, t_lem *lem)
{
	int			i;

	i = 0;
	while(room->tab && room->tab[i])
	{
		if (!ft_strcmp(lem->start, (room->tab[i])->name))
			moove(room->tab, i);
		else if (!ft_strcmp(lem->end, (room->tab[i])->name))
		{
			deltabroom(&(room->tab));
			room->tab = alloctabroom(1);
			room->tab[0] = lem->tab[hash(lem->end)];
			deltabroom(&((room->tab[0])->tab));
			(room->tab[0])->dist = 0;
			return (1);
		}
		else
			i++;
	}
	if (room && (!room->tab || !room->tab[0]))
		return (1);
	return (0);
}


t_lemroom		*connect(t_lemroom *room, t_lem *lem)
{
	int			i;
	t_lemroom	*room1;

	if (room && !ft_strcmp(room->name, lem->end))
	{
		room->dist = 0;
		deltabroom(&room->tab);
	}
	else if (room && room->tab)
	{
		if ((i = filter(room, lem)))
		{
			room->dist = room->tab[0]->dist + 1;
			return (room);
		}
		i = 0;
		while (room && room->tab[i])
		{
			room1 = (room->tab[i]);
			if (lem->tab[hash(room1->name)])
			{
				room->tab[i] = lem->tab[hash(room1->name)];
				delroom(&room1);
				i++;
			}
			else
				moove(room->tab, i);
		}
	}
	return (room);
}

t_lemroom		**allconnect(t_lemroom **room, t_lem *lem)
{
	int			i;
	t_lemroom	**tab;
	t_lemroom   *room1;

	i = 0;
	tab = NULL;
	while(room && room[i])
	{
		room1 = connect(room[i], lem);
		if (!ft_strcmp(lem->start, room1->name))
			lem->tab[hash(room1->name)] = NULL;
		tab = merge(tab, room1->tab);
		i++;
	}
	if (tab && !tab[0])
		deltabroom(&tab);
	return (tab);
}