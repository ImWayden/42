/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 01:13:58 by msarr             #+#    #+#             */
/*   Updated: 2014/12/02 03:46:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


t_link		*new_link(t_room *room)
{
	t_link	*link;

	link = (t_link *)malloc(sizeof(t_link));
	if (link)
	{
		link->room = room;
		link->next = NULL;
	}
	return (link);
}

int			add_link(char *str, t_lem *lem)
{
	char	**tab;
	t_room	*room;
	t_link	*link;

	if ((tab = ft_strsplit(str, '-')))
	{
		
		room = lem->tab[hash(tab[0])];
		link = new_link(lem->tab[hash(tab[1])]);
		link->next = room->lst;
		room->lst = link;
		room = lem->tab[hash(tab[1])];
		link = new_link(lem->tab[hash(tab[0])]);
		link->next = room->lst;
		room->lst = link;
		return (1);
	}
	return (0);
}