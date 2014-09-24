/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/06/19 16:12:48 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void			transfert(t_lemroom *room, t_lem *pars, int j)
{
	int				i;

	i = 0;
	while (room && room->tab && room->lem && room->lem <= pars->j && room->tab[i])
	{
		if (room->tab[i] == pars->lem_end)
		{
			(pars->lem_end->lem)++;
			putroom(room, room->tab[i]);
			if (room != pars->lem_start)
				room->lem = 0;
			else
				(room->lem)++;
		}
		else if (!(room->tab[i])->lem && (room->tab[i])->dist <= j)
		{
			room->tab[i]->lem = room->lem;
			putroom(room, room->tab[i]);
			if (room != pars->lem_start)
				room->lem = 0;
			else
				(room->lem)++;
		}
		i++;
	}
}

void				connect(t_lemroom *room, t_lem *lem)
{
	int				i;
	t_lemroom		*room1;

	if (has_end(room, lem))
		return ;
	if (room)
	{
		i = 0;
		while (room && room->tab && room->tab[i])
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
}

void				send(t_lemroom *room, t_lem *pars)
{
	int				i;
	int				j;

	if (room != pars->lem_end)
	{
		i = 0;
		while (room && room->tab && room->tab[i])
		{
			send(room->tab[i], pars);
			i++;
		}
		if (pars->lem_start->lem <= pars->j)
			j = (pars->j - pars->lem_start->lem + 1) * pars->lem_start->dist;
		else
			j = pars->lem_start->dist;
		if (room->lem <= pars->j)
			transfert(room, pars, j);
	}
}

void				lemin(t_lem *lem)
{
	t_lemroom		*room;
	t_lemroom		**tab;

	ft_putstr("SENDING LEMS....\n");
	room = lem->lem_start;
	room->lem = 1;
	connect(room, lem);
	purge(room->tab, lem);
	tab = room->tab;
	while ((tab = allconnect(tab, lem)))
		purge(tab, lem);
	weight(room, lem);
	if (room->dist < 1000)
	{
		while (lem->lem_end->lem < lem->j)
		{
			send(room, lem);
			ft_putendl(NULL);
		}
	}
	else
		ft_putcolorstr("ERROR\n", RED);
	delroom(&room);
}
