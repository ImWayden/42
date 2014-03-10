/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 15:52:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void				weight(t_lemroom *room, t_lem *lem)
{
	int				i;

	i = 0;
	while (room && room->tab && (room->tab)[i])
	{
		weight((room->tab)[i], lem);
		i++;
	}
	if (room && !room->tab && room->name && !ft_strcmp(room->name, lem->end))
		room->dist = 0;
	else if (room && !room->tab && ft_strcmp(room->name, lem->end))
		room->dist = 100000;
	else if (room && room->tab && !(room->tab)[0]
							   && ft_strcmp(room->name, lem->end))
		room->dist = 100000;
	else if (room && room->tab && (room->tab)[0])
	{
		if (!ft_strcmp(((room->tab)[0])->name, lem->end))
			room->dist = 1;
		else
		{
			sort(room->tab);
			room->dist = ((room->tab)[0])->dist + 1;
		}
	}
}
