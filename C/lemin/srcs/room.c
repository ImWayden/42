/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/19 14:11:19 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemroom		*allocroom(char *str)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		room->name = ft_strdup(str);
		room->dist = 1000;
		room->lem = 0;
		room->step = 0;
		room->tab = NULL;
	}
	return (room);
}

void			delroom(t_lemroom **room)
{
	int			i;

	i = 0;
	if (room && *room)
	{
		if ((*room)->tab)
		{
			while ((*room)->tab[i])
			{
				delroom(&((*room)->tab[i]));
				i++;
			}
		}
		if ((*room)->name)
			ft_memdel((void **)&((*room)->name));
		ft_memdel((void **)room);
	}
}

t_lemroom		**alloctabroom(int i)
{
	t_lemroom	**tab;

	if ((tab = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + 1))))
		tab[i] = NULL;
	i = 0;
	while (tab && tab[i])
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

void			deltabroom(t_lemroom ***room)
{
	int			i;

	i = 0;
	while (room && *room && (*room)[i])
	{
		delroom(&(*room)[i]);
		i++;
	}
	if (room && *room)
		ft_memdel((void **)room);
}

