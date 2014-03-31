/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/03/13 14:16:15 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int					send(t_lemroom *room, t_lem *pars)
{
	t_lemroom		*room1;
	int				i;

	i = 0;
	while (pars->j && room && room->tab && room->tab[i])
	{
		room1 = room->tab[i];
		if (room1->dist < room->dist || room1->dist < (room->dist * pars->j))
		{
			if (ft_strcmp(room1->name, pars->end))
				room1->lem = pars->j;
			else
				(room1->lem)++;
			ft_putstr("L");
			ft_putnbr(room->lem - pars->j + 1);
			ft_putstr("-");
			ft_putstr(room1->name);
			(pars->j)--;
			i++;
		}
		else
			break;
	}
	ft_putendl(NULL);
	return (pars->j);
}

int					trans1(t_lemroom *room, t_lem *pars, int j)
{
	t_lemroom		*room1;

	if (room && room->tab && room->tab[0] && ft_strcmp(room->name, pars->end))
	{
		room1 = room->tab[0];
		trans1(room1, pars, j);
		if (room->lem && !room1->lem)
		{
			putroom(room, room1, j);
			if (ft_strcmp(room1->name, pars->end))
				room1->lem = room->lem;
			else
				(room1->lem)++;
			room->lem = 0;
		}
		else if (room->lem && !ft_strcmp(room1->name, pars->end))
		{
			putroom(room, room1, j);
			(room1->lem)++;
			if (ft_strcmp(room->name, pars->start))
				room->lem = 0;
		}
	}
	return (0);
}

void					transtab(t_lemroom *room, t_lem *pars, int j)
{
	int				i;
	t_lemroom		*room1;

	i = 0;
	while (room->lem && room->tab && room->tab[i] && room->lem)
	{
		room1 = room->tab[i++];
		if (room1->dist < room->dist || room1->dist < (room->dist * pars->j))
		{
			if (room->lem && !room1->lem)
			{
				if (ft_strcmp(room1->name, pars->end))
					room1->lem = room->lem;
				else
					(room1->lem)++;
				room->lem = 0;
			}
			else if (room->lem && !ft_strcmp(room1->name, pars->end))
			{
				(room1->lem)++;
				if (ft_strcmp(room->name, pars->start))
					room->lem = 0;
			}
			putroom(room, room1, j);
		}
	}
}

int					trans2(t_lemroom *room, t_lem *pars, int j)
{
	int				i;

	i = 0;
	while (room->tab && room->tab[i] && ft_strcmp(room->name, pars->end))
	{
		trans2(room->tab[i], pars, j);
		i++;
	}
	transtab(room, pars, j);
	return (0);
}

void				lemin(t_lem *lem)
{
	t_lemroom		*room;
	int				i;
	t_lemroom		*room1;
	t_lemroom		**tab;

	ft_putstr("SENDING LEMS....\n");
	room = lem->tab[hash(lem->start)];
	room1 = lem->tab[hash(lem->end)];
	room->lem = lem->j;
	lem->tab[hash(lem->start)] = NULL;
	connect(room, lem);
	tab = room->tab;
	while (tab)
		tab = allconnect(tab, lem);
	if (room->tab)
	weight(room, lem);
	while (room->dist < 10000 && room1->lem < room->lem)
	{
		trans1(room->tab[0], lem, room->lem);
		i = 1;
		while (room && room->tab && room->tab[i])
			trans2(room->tab[i++], lem, room->lem);
		send(room, lem);
	}
	if (room->dist >= 10000)
		ft_putcolorstr("NO WAY FOUND!\n", RED);
	deltabroom(&room1->tab);
	deltabroom(&room->tab);
	//free(room1->name);
	//free(room->name);

	sleep(30);
}
