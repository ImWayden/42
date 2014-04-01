/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/18 23:57:31 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				tabroomlen(t_lemroom **tabroom)
{
	int		i;

	i = 0;
	while (tabroom && tabroom[i])
		i++;
	return (i);
}

void			putroom(t_lemroom *room, t_lemroom *room1, int j)
{
	ft_putstr("L");
	ft_putnbr(j - room->lem + 1);
	ft_putstr("-");
	ft_putstr(room1->name);
	ft_putchar(' ');
}

t_lemroom		*allocroom(char *str, t_lem *lem)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		room->name = ft_strdup(str);
		if (lem->end && lem->end && !ft_strcmp(str, lem->end))
			room->dist = 0;
		else
			room->dist = 10000;
		room->lem = 0;
		room->step = 0;
		room->tab = NULL;
	}
	return (room);
}

void			addroom(t_lemroom *room, char *str, t_lem *lem)
{
	int			i;
	t_lemroom	**tmp;

	if (room && room->dist == 10000)
	{
		if (!ft_strcmp(str, lem->end))
		{
			if (room->tab)
				deltabroom(&(room->tab));
			room->tab = alloctabroom(1);
			room->tab[0] = lem->tab[hash(lem->end)];
			room->dist = 1;
		}
		else if (ft_strcmp(str, lem->start))
		{
			i = tabroomlen(room->tab);
			tmp = alloctabroom(i + 1);
			if (tmp)
				tmp[i] = allocroom(str, lem);
			while (--i >= 0)
				tmp[i] = room->tab[i];
			free(room->tab);
			room->tab = tmp;
		}
	}
}

void			delroom(t_lemroom **room)
{
	int			i;

	i = 0;
	if (*room)
	{
		if (*room && (*room)->tab && (*room)->tab[i])
			deltabroom(&(*room)->tab);
		if ((*room)->name != NULL)
			ft_memdel((void **)&((*room)->name));
		if (*room)
			free(*room);
		*room = NULL;
	}
}