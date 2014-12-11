/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/12/11 11:28:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "fdf.h"

t_trans			*putroom(t_trans *trans, t_room *room, t_room *room1)
{
	if (!trans)
		ft_putstr("L");
	else
		ft_putstr(" L");
	ft_putnbr(room->lem);
	ft_putstr("-");
	ft_putstr(room1->name);
	return (add_trans(trans, room, room1));
}


t_trans		*send(t_room *r, t_lem *lem, t_trans *t)
{
	t_link	*l;
	t_room	*tmp;
	int		i;

	l = r->lst;
	while (l && r->dist && r->dist < 1000)
	{
		tmp = l->room;
		if (tmp->dist && tmp->dist < 1000 && tmp != lem->start && !tmp->s)
		{
			tmp->s = 1;
			t = send(tmp, lem, t);
		}
		l = l->next;
	}
	l = r->lst;
	while (l && r->lem  && r->lem <= lem->nbr && r->dist && r->dist < 1000)
	{
		tmp = l->room;
		i = lem->nbr - lem->start->lem;
		if (i <= 0)
			i = 1;
		if ((!tmp->lem || tmp == lem->end) && tmp->dist >= 0 && (tmp->dist <= lem->start->dist * i) && !r->r)
		{
			if (tmp == lem->end)
			{
				tmp->lem++;
				t = putroom(t, r, tmp);
				if (r == lem->start)
					r->lem++;
				else
					r->lem = 0;
				break ;
			}
			else if (tmp != lem->start)
			{
				tmp->lem = r->lem;
				tmp->r = 1;
				t = putroom(t, r, tmp);
				if (r == lem->start)
					r->lem++;
				else
					r->lem = 0;
			}
		}
		l = l->next;
	}
	return (t);
}

void		put_trans(t_trans *trans);

void				lemin(t_lem *lem)
{
	int				i;
	t_trans			*t;

	while (lem->end->lem < lem->nbr)
	{
		i = 0;
		t = NULL;
		while (i < 1000)
		{
			if (lem->tab[i])
			{
				lem->tab[i]->s = 0;
				lem->tab[i]->r = 0;
			}
			i++;
		}
		send(lem->start, lem, t);
		ft_putendl("");
		
	}
}
