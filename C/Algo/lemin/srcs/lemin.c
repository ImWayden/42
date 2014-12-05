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

t_trans			*putroom(t_trans *trans, t_room *room, t_room *room1)
{
	ft_putstr("L");
	ft_putnbr(room->lem);
	ft_putstr("-");
	ft_putstr(room1->name);
	ft_putchar(' ');
	return (add_trans(trans, room, room1));
}

static t_trans	*transfert(t_room *room, t_lem *lem, t_trans *trans)
{
	t_link		*l;
	int			i;

	l = room->lst;
	while (l && room->lem && room->lem <= lem->nbr)
	{
		i = 0;
		if (l->room == lem->end && (i = 1))
			lem->end->lem++;
		else if (!l->room->lem && l->room->dist < room->dist && (i = 2))
			l->room->lem = room->lem;
		if (i)
		{
			trans = putroom(trans, room, l->room);
			if (room != lem->start)
				room->lem = 0;
			else
				(room->lem)++;
			if (i == 1)
				break;
		}
		l = l->next;
	}
	return (trans);
}

static t_trans	*send(t_room *room, t_lem *lem, t_trans *t)
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
				t = send(l->room, lem, t);
			}
			l = l->next;
		}
		if (room->lem && room->lem <= lem->nbr)
			t = transfert(room, lem, t);
	}
	return (t);
}

void		put_trans(t_trans *trans);

void				lemin(t_lem *lem, t_env env)
{
	t_trans			*t;

	t = NULL;
	while (lem->end->lem < lem->nbr)
	{
		lem->start->step++;
		if (lem->g)
		{
			draw_lem(&env, env.room, t);
			put_trans(t);	
			//clean(env);
		}
		t = NULL;
		t = send(lem->start, lem, t);
		ft_putendl(NULL);
	}
	if (lem->g)
		draw_lem(&env, env.room, t);
}
