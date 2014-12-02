/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:59:59 by msarr             #+#    #+#             */
/*   Updated: 2014/12/02 03:01:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		way(t_room *room, t_lem *lem)
{
	t_link	*lnk;
	t_room	*r;

	lnk = room->lst;
	while (lnk)
	{
		r = lnk->room;
		if (r == lem->start)
		{
			if (room->dist < lem->start->dist)
				lem->start->dist = room->dist + 1;
		}
		if (r == lem->end)
			;
		else if (r->dist > 10000)
		{
			r->dist = room->dist + 1;
			way(r, lem);
		}
		lnk = lnk->next;
	}
	return (0);
}
