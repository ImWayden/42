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
		ft_putcolorstr("R_", RED);
		ft_putcolorstr(room->name, RED);
		ft_putcolorstr("- DIST_", RED);
		ft_putnbr(room->dist);
		ft_putcolorstr(" : lem : ", RED);
		ft_putnbr(room->lem);
		ft_putcolorstr(" : ", RED);
		while (room->tab && (room->tab)[i])
		{
			ft_putstr(((room->tab)[i])->name);
			ft_putstr(" ");
			i++;
		}
		ft_putendl(NULL);
		i = 0;
		while (room->tab && (room->tab)[i])
		{
			putroom((room->tab)[i]);
			ft_putendl(NULL);
			i++;
		}
	}
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
		while ((*room)->tab && (*room)->tab[i])
		{
			delroom(&((*room)->tab[i]));
			i++;
		}
		if ((*room)->tab)
			free((*room)->tab);
		if ((*room)->name)
			ft_memdel((void **)&((*room)->name));
		free(*room);
		*room = NULL;
	}
}
