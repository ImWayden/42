/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/19 01:03:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				send(t_lemroom *room, t_lem *pars)
{
	t_lemroom		*room1;
	static int				lem = 1;
	int				i;

	i = 0;
	while (lem && room && room->tab && room->tab[i])
	{
		room1 = room->tab[i];
		if (room1->dist < room->dist || room1->dist < (room->dist * pars->j))
		{
			if (ft_strcmp(room1->name, pars->end))
				room1->lem = lem;
			else
				(room1->lem)++;
			lem++;
			(pars->j)--;
			room->lem = 0;
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

	if(room && room->tab && room->tab[0] && ft_strcmp(room->name, pars->end))
	{
		room1 = room->tab[0];
		trans1(room1, pars);
		if (room->dist && !room1->dist)
		{
			if (ft_strcmp(room1->name, pars->end))
				room1->dist = room->dist;
			else
				(room1->dist)++;
			room->dist = 0;
		}
	}
	return (0);
}


int 				main()
{
	t_lem			*lem;
	int				i;
	t_lemroom		*room;
	t_lemroom		**tab;

	lem = parse();
	if (lem && lem->start && lem->end && lem->j)
	{
		ft_putstr("SENDING LEMS....\nSTART :");	
		ft_putendl(lem->start);
		ft_putstr("END :");	
		ft_putendl(lem->end);
		room = lem->tab[hash(lem->start)];
		room->lem = lem->j;
		lem->tab[hash(lem->start)] = NULL;
		connect(room, lem);
		putroom(room);
		tab = room->tab;
		if (room && room->tab)
		{
			while (tab)
				tab = allconnect(tab, lem);
			i = 1;
			weight(room, lem);
			trans1(room->tab[0], lem);
			send(room, lem);
			putroom(room);
			ft_putnbr(i);
		}
	}
	else
		ft_putcolorstr("WRONG MAP !\n", RED);
	//dellem(&lem);
	return 0;
}
