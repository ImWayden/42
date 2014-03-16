/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/13 14:07:09 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"


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
		lem->tab[hash(room->name)] = NULL;
		room = connect(room, lem);
		tab = room->tab;
		while (tab)
		{
			//verif(tab, lem);
			tab = allconnect(tab, lem);
		}
		putroom(room);	
	}
	else
		ft_putcolorstr("WRONG MAP !\n", RED);
	//dellem(&lem);
	sleep(15);
	return 0;
}
