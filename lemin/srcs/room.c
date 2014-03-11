/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 22:59:14 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			tabroomlen(t_lemroom **tabroom)
{
	int		i;

	i = 0;
	while (tabroom && tabroom[i])
		i++;
	return (i);
}

void		putroom(t_lemroom *room)
{
	int		i;

	i = 0;
	if (room)
	{
		ft_putcolorstr("R", RED);
		ft_putcolorstr(room->name, RED);
		ft_putcolorstr("- DIST", RED);
		ft_putnbr(room->dist);
		ft_putcolorstr(" : ", RED);
		while (room->tab && (room->tab)[i])
		{
			putroom((room->tab)[i]);
			ft_putendl(NULL);
			i++;
		}
		ft_putendl(NULL);
	}
}

t_lemroom		*allocroom(char *str)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		room->name = ft_strdup(str);
		room->dist = 10000;
		room->tab = NULL;
	}
	return (room);
}

t_lemroom		**alloctabroom(int i)
{
	t_lemroom	**tab;

	if (!i)
		return (NULL);
	tab = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + 1));
	while (tab && i)
	{
		tab[i] = NULL;
		i--;
	}
	return (tab);
}

void		listtotab(t_lemlist *list, t_lem *lem, t_lemroom *room, int j)
{
	int		i;

	i = 0;
	while (list && room && i < j)
	{
		if (list->str && ft_strcmp(list->str, lem->start) && ft_strcmp(list->str, room->name))
			((room->tab)[i]) = allocroom(list->str);		
		list = list->next;
		i++;
	}
}
