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

int				send(t_lemroom *room, t_lem *pars)
{
	t_lemroom		*room1;
	static int				lem = 1;
	int				i;

	i = 0;
	while (lem  <= room->lem && room && room->tab && room->tab[i])
	{
		room1 = room->tab[i];
		if (room1->dist < room->dist || room1->dist < (room->dist * pars->j))
		{
			if (ft_strcmp(room1->name, pars->end))
				room1->lem = lem;
			else
				(room1->lem)++;
			ft_putstr("R");
			ft_putstr(room1->name);
			ft_putstr("-L");
			ft_putnbr(lem);
			lem++;
			(pars->j)--;
			i++;
		}
		else
			break;
	}
	return (lem);
}

int				trans1(t_lemroom *room, t_lem *pars)
{
	t_lemroom		*room1;

	if (room && room->tab && room->tab[0] && ft_strcmp(room->name, pars->end))
	{
		room1 = room->tab[0];
		trans1(room1, pars);
		if (room->lem && !room1->lem)
		{
			if (ft_strcmp(room1->name, pars->end))
				room1->lem = room->lem;
			else
				(room1->lem)++;
			ft_putstr("R");
			ft_putstr(room1->name);
			ft_putstr("-L");
			ft_putnbr(room1->lem);
			ft_putchar(' ');
			room->lem = 0;
		}
		else if (room->lem && !ft_strcmp(room1->name, pars->end))
		{
			(room1->lem)++;
			ft_putstr("R");
			ft_putstr(room1->name);
			ft_putstr("-L");
			ft_putnbr(room1->lem);
			ft_putchar(' ');
			if (ft_strcmp(room->name, pars->start))
				room->lem = 0;
		}
	}
	return (0);
}

int				trans2(t_lemroom *room, t_lem *pars)
{
	t_lemroom		*room1;
	int				i;

	i = 0;
	while (pars && room->tab && room->tab[i] && ft_strcmp(room->name, pars->end))
	{
		trans2(room->tab[i], pars);
		i++;
	}
	i = 0;
	while (pars && room->tab && room->tab[i] && room->lem)
	{
		room1 = room->tab[i];
		if (room1->dist < room->dist || room1->dist < (room->dist * pars->j))
		{
			if (room->lem && !room1->lem)
			{
				if (ft_strcmp(room1->name, pars->end))
					room1->lem = room->lem;
				else
					(room1->lem)++;
				ft_putstr("R");
				ft_putstr(room1->name);
				ft_putstr("-L");
				ft_putnbr(room1->lem);
				room->lem = 0;
			}
			else if (room->lem && !ft_strcmp(room1->name, pars->end))
			{
				ft_putstr("R");
				ft_putstr(room1->name);
				ft_putstr("-L");
				ft_putnbr(room->lem);
				(room1->lem)++;
				if (ft_strcmp(room->name, pars->start))
					room->lem = 0;
			}
			i++;
		}
		else
			break;
	}                                
	return (0);
}

void				lemin(t_lem *lem)
{
	t_lemroom		*room;
	int				i;
	t_lemroom		*room1;
	t_lemroom		**tab;

	ft_putstr("SENDING LEMS....\n:");
	room = lem->tab[hash(lem->start)];
	room1 = lem->tab[hash(lem->end)];
	room->lem = lem->j;
	lem->tab[hash(lem->start)] = NULL;
	connect(room, lem);
	putroom(room);
	tab = room->tab;
	while (tab)
		tab = allconnect(tab, lem);
	if (room->tab)
	weight(room, lem);
	while (room->dist < 10000 && room1->lem < room->lem)
	{
		trans1(room->tab[0], lem);
		i = 1;
		while (room && room->tab && room->tab[i])
			trans2(room->tab[i++], lem);
		send(room, lem);
		ft_putendl(NULL);
	}
	if (room->dist >= 10000)
		ft_putcolorstr("NO WAY FOUND!\n", RED);
	putroom(room);
}
