/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/12/02 12:27:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			putroom(t_room *room, t_room *room1)
{
	ft_putstr("L");
	ft_putnbr(room->lem);
	ft_putstr("-");
	ft_putstr(room1->name);
	ft_putchar(' ');
}

static void	transfert(t_room *room, t_lem *lem)
{
	t_link	*l;

	l = room->lst;
	while (l && room->lem <= lem->nbr)
	{
		if (l->room == lem->end)
		{
			lem->end->lem++;
			putroom(room, l->room);
			if (room != lem->start)
				room->lem = 0;
			else
				(room->lem)++;
			break;
		}
		else if (!l->room->lem && l->room->dist < room->dist)
		{
			l->room->lem = room->lem;
			putroom(room, l->room);
			if (room != lem->start)
				room->lem = 0;
			else
				(room->lem)++;
		}
		l = l->next;
	}
}

static void	send(t_room *room, t_lem *lem)
{
	t_link	*l;

	if (room != lem->end)
	{
		l = room->lst;
		while (l)
		{
			if (room->step > l->room->step && l->room != lem->start)
			{
				l->room->step++;
				send(l->room, lem);
			}
			l = l->next;
		}
		if (room->lem)
			transfert(room, lem);
	}
}

void				lemin(t_lem *lem)
{
	t_room		*room;

	ft_putstr("SENDING LEMS....\n");
	room = lem->start;
	room->lem = 1;
	ft_putnbr(lem->start->dist);
	way(lem->end, lem);
	ft_putnbr(lem->start->dist);
	if (room->dist < 1000)
	{
		while (lem->end->lem < lem->nbr)
		{
			room->step++;
			send(room, lem);
			ft_putendl(NULL);
		}
	}
	else
		ft_putstr("ERROR\n");
}
