/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:59:59 by msarr             #+#    #+#             */
/*   Updated: 2014/12/10 06:07:02 by msarr            ###   ########.fr       */
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
		if (r != lem->end)
		{
			if (r->dist > room->dist)
			{
				r->dist = room->dist + 1;
				if (r != lem->start)
					way(r, lem);
			}
		}
		lnk = lnk->next;
	}
	return (0);
}
