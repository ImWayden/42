/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/07 18:46:02 by msarr            ###   ########.fr       */
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
		tabroom = recupfirstroom(room, lem);
		while (tabroom && ft_strcmp((tabroom[0])->name, lem->end))
			tabroom = recupnextroom(tabroom, lem);
	}
	return 0;
}
