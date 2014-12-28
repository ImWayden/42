/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 21:45:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		putroom(t_lem *lem, t_room *room, t_room *room1)
{
	if ((lem->flag) && !(lem->flag = 0))
		ft_putstr("L");
	else
		ft_putstr(" L");
	ft_putnbr(room->lem);
	ft_putstr("-");
	ft_putstr(room1->name);
}

static void		send_list(t_room *r, t_lem *lem)
{
	t_link		*l;
	t_room		*tmp;

	l = r->lst;
	while (l && r->dist && r->dist < 1000)
	{
		tmp = l->room;
		if (tmp->dist && tmp->dist < 1000 && tmp != lem->start && !tmp->s)
		{
			tmp->s = 1;
			send(tmp, lem);
			if (tmp->lem)
				tmp->s = 0;
		}
		l = l->next;
	}
}

static void		trans(t_room *r, t_room *tmp, t_lem *lem)
{
	if (tmp == lem->end)
	{
		tmp->lem++;
		putroom(lem, r, tmp);
		if (r == lem->start)
			r->lem++;
		else
			r->lem = 0;
	}
	else
	{
		tmp->lem = r->lem;
		tmp->r = 1;
		putroom(lem, r, tmp);
		if (r == lem->start)
			r->lem++;
		else
			r->lem = 0;
	}
}

void			send(t_room *r, t_lem *lem)
{
	t_link		*l;
	t_room		*tmp;
	int			i;

	send_list(r, lem);
	l = r->lst;
	while (l && r->lem && r->lem <= lem->nbr && r->dist && r->dist < 1000
		&& !r->r)
	{
		tmp = l->room;
		if ((i = lem->nbr - lem->start->lem) <= 0)
			i = 1;
		if ((!tmp->lem || tmp == lem->end) && tmp->dist >= 0
					&& (tmp->dist <= lem->start->dist * i))
		{
			trans(r, tmp, lem);
			if (tmp == lem->end)
				break ;
		}
		l = l->next;
	}
}

int				lemin(t_lem *lem)
{
	int			i;

	while (lem->end->lem < lem->nbr)
	{
		lem->flag = 1;
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
		send(lem->start, lem);
		ft_putendl("");
	}
	return (1);
}
