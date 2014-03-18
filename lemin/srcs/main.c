/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/17 14:41:51 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int					send(t_lemroom *room, int lem)
{
	t_lemroom		*room1;
	int				i;

	i = 0;
	while (room && room->tab && room->tab[i] && room->lem)
	{
		send(room->tab[i], (room->tab[i])->lem);
		i++;
	}
	i = 0;
	while (lem && room && room->tab && room->tab[i])
	{
		room1 = room->tab[i];
		if (room1->dist < 10000)
		{
			room1->lem = lem;
			lem++;
			room->lem = 0;;
		}
		i++;
	}
	return (lem);
}




int 				main()
{
	t_lem			*lem;
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
		if (room->dist == 10000)
		{
			while (tab)
				tab = allconnect(tab, lem);
			weight(room, lem);
			send(room, 1);
			putroom(room);
		}
	}
	else
		ft_putcolorstr("WRONG MAP !\n", RED);
	//dellem(&lem);
	return 0;
}
