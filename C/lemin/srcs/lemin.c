/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/06/19 16:12:48 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void				purge(t_lemroom **tab, t_lem *lem)
{
	int				i;

	i = 0;
	while (tab && tab[i])
	{
		putroomb(tab[i]);
		lem->tab[hash(tab[i]->name)] = NULL;
		i++;
	}
}			

void				lemin(t_lem *lem)
{
	t_lemroom		*room;
	t_lemroom		**tab;

	ft_putstr("SENDING LEMS....\n");
	room = lem->lem_start;
	room->lem = 1;
	connect(room, lem);
	purge(room->tab, lem);
	tab = room->tab;
	while ((tab = allconnect(tab, lem)))
		purge(tab, lem);
	weight(room, lem);
	if (room->dist < 1000)
	{
		while (lem->lem_end->lem < lem->j)
		{
			send(room, lem);
			ft_putendl(NULL);
			sleep(5);
		}
	}
	else
		ft_putcolorstr("WRONG MAP !\n", RED);
}
