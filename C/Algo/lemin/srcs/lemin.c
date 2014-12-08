/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/12/08 04:32:43 by msarr            ###   ########.fr       */
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
	while (l && room->lem)
	{
		i = 0;
		if (l->room == lem->end && (i = 1))
			lem->end->lem++;
		else if (!l->room->lem && l->room != lem->start && (i = 2) && !l->room->r && l->room->dist < room->dist)
			l->room->lem = room->lem;
		if (i)
		{
			l->room->r = 1;
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

	if (room->dist && room->dist < 1000 && !room->s)
	{
		room->s = 1;

		l = room->lst;
		while (l)
		{
			if (l->room != lem->start && !l->room->s)
				t = send(l->room, lem, t);
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
	int				i;

	t = NULL;
	while (lem->end->lem < lem->nbr)
	{
		t = NULL;
		i = 0;
		while (i < 1000)
		{
			if (lem->tab[i])
			{
				lem->tab[i]->s = 0;
				lem->tab[i]->r = 0;
			}
			i++;
		}
		t = send(lem->start, lem, t);
		ft_putendl(NULL);
		if (lem->g)
		{
			draw_lem(&env, env.room, t);
			put_trans(t);	
			//clean(env);
		}
	}
	if (lem->g)
		draw_lem(&env, env.room, t);
}
