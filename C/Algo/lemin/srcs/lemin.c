/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/12/03 22:56:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "fdf.h"

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
	t_env		env;

	ft_putstr("SENDING LEMS....\n");
	room = lem->start;
	room->lem = 1;
	way(lem->end, lem);
	env.pad = 24;
	env.x = 24;
	env.y =  24;
	env.w = env.x++ * env.pad * 2;
	env.h = env.y++ * env.pad * 2;
	env.room = lem->tab;
	project(&env, env.room);
	if ((env.ptr = mlx_init()) == NULL)
		return ;
	if (!(env.win = mlx_new_window(env.ptr, env.w, env.h, "fdf")))
		return ;
	if (room->dist < 1000)
	{
		while (lem->end->lem < lem->nbr)
		{
			room->step++;
			send(room, lem);
			draw_lem(&env, env.room);	
			ft_putendl(NULL);
			sleep (3);
		}
	}
	else
		ft_putstr("ERROR\n");
}
