/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 23:02:33 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 				main()
{
	t_lem			*lem;
	t_lemroom		*room;
	t_lemroom		*room1;

	lem = parse();
	if (lem->start && lem->end && lem->j)
	{
		ft_putstr("SENDING LEMS....\nSTART :");	
		ft_putendl(lem->start);
		ft_putstr("END :");	
		ft_putendl(lem->end);
		room = newroom(lem->start, lem);
		room1 = newendroom(lem->end, lem);
		//delroomlist(room, lem);
		//delroomlist(room1, lem);
		putroom(room);
		putroom(room1);
	}
	return 0;
}
