/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:59:59 by msarr             #+#    #+#             */
/*   Updated: 2014/06/19 17:03:47 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int					has_end(t_lemroom *room, t_lem *lem)
{
	int				i;

	i = 0;
	while (room && room->tab && room->tab[i])
	{
		if (!ft_strcmp((room->tab[i])->name, lem->end))
		{
			deltabroom(&(room->tab));
			room->tab = alloctabroom(1);
			(room->tab)[0] = lem->lem_end;
			return (1);
		}
		i++;
	}
	return (0);
}

void				weight(t_lemroom *room, t_lem *lem)
{
	int				i;

	i = 0;
	while (room && room->tab && (room->tab)[i])
	{
		weight((room->tab)[i], lem);
		i++;
	}
	if (room && room->tab && room->tab[0])
	{
		if (!ft_strcmp((room->tab[0])->name, lem->end))
			room->dist = 1;
		else
		{
			sort(room->tab);
			room->dist = ((room->tab)[0])->dist + 1;
		}
	}
}

void				purge(t_lemroom **tab, t_lem *lem)
{
	int				i;

	i = 0;
	while (tab && tab[i])
	{
		lem->tab[hash(tab[i]->name)] = NULL;
		i++;
	}
}

t_lemroom			**allconnect(t_lemroom **room, t_lem *lem)
{
	int				i;
	t_lemroom		**tab;
	t_lemroom		**tmp;

	i = 0;
	tab = NULL;
	while (room && room[i])
	{
		connect(room[i], lem);
		tmp = room[i]->tab;
		if (tmp && tmp[0] && ft_strcmp(tmp[0]->name, lem->end))
			tab = merge(&tab, tmp);
		i++;
	}
	return (tab);
}
