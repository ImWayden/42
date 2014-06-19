/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/06/18 14:34:38 by mozzie           ###   ########.fr       */
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
	//int				i;
	//t_lemroom		*room1;
	t_lemroom		**tab;//

	ft_putstr("SENDING LEMS....\n");
	room = lem->lem_start;
	//room1 = lem->lem_end;
	room->lem = lem->j;
	connect(room, lem);
	purge(room->tab, lem);
	tab = allconnect(room->tab, lem);
	if (!tab)
		purge(room->tab, lem);
}
