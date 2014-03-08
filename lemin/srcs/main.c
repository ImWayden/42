/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/08 03:03:13 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 				main()
{
	t_lem			*lem;
	t_lemroom		**tabroom;
	t_lemroom		*room;

	lem = parse();
	lem->tab[hashcode(lem->end)] = NULL;
	if (lem->start && lem->end && lem->j)
	{
		ft_putstr("SENDING LEMS....\nSTART :");	
		ft_putendl(lem->start);
		ft_putstr("END :");	
		ft_putendl(lem->end);
		room = newroom(lem->start);
		ft_putendl(room->name);
		tabroom = recupfirstroom(room, lem, NULL);
		while (tabroom && tabroom[0] && ft_strcmp((tabroom[0])->name, lem->end))
			tabroom = recupnextroom(tabroom, lem);
		weight(room, lem);
		ft_putendl("ok");
		ft_putendl(NULL);
		ft_putnbr(room->dist);
	}
	return 0;
}
