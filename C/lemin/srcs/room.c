/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/18 13:37:08 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void			putroomb(t_lemroom *room)
{
	int		i = 0;

	if (room && room->tab)
	{
		while ((room->tab)[i])
		{
			putroomb((room->tab)[i]);
			i++;
		}
	}
	if (room)
		ft_putendl(room->name);
}

t_lemroom		*allocroom(char *str)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		room->name = ft_strdup(str);
		room->dist = 0;
		room->lem = 0;
		room->step = 0;
		room->tab = NULL;
	}
	return (room);
}

void			addroom(t_lemroom *room, char *str)
{
	int			i;
	t_lemroom	**tmp;

	if (room)
	{
		i = tabroomlen(room->tab);
		if ((tmp = alloctabroom(i + 1)))
			tmp[i] = allocroom(str);
		while (--i >= 0)
		{
			tmp[i] = room->tab[i];
			room->tab[i] = NULL;
		}
		deltabroom(&room->tab);
		room->tab = tmp;
	}
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