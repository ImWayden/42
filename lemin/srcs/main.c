/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/03/13 09:00:35 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void				mainverif(t_lemroom **start, t_lem *lem)
{
	if ((*start)->dist == -1)
	{
		ft_putendl("THERE IS NO WAY BETWEEN : ");
		ft_putcolorstr(lem->start, GREEN);
		ft_putstr(" AND ");
		ft_putcolorstr(lem->end, YELLOW);
		ft_putendl(NULL);
	}
	else if ((*start)->dist == 10000)
	{
		*start = connect(*start, lem);
		if ((*start)->tab)
			epure(((*start)->tab)[0], lem);
		//dellist(&(lem->tab[(hashcode(lem->start))]));
	}
}

int 				main()
{
	t_lem			*lem;
	t_lemroom		*room;
	t_lemroom		*room1;

	lem = parse();
	if (lem && lem->start && lem->end && lem->j)
	{
		ft_putstr("SENDING LEMS....\nSTART :");	
		ft_putendl(lem->start);
		ft_putstr("END :");	
		ft_putendl(lem->end);
		room = newroom(lem->start, lem);
		room1 = newendroom(lem->end, lem);
		mainverif(&room, lem);
		putroom(room);
		putroom(room1);
	}
	else
		ft_putcolorstr("WRONG MAP !\n", RED);
	return 0;
}
