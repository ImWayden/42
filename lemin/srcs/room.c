/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 02:57:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemroom		*newroom(char *str)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		if (str)
			room->name = ft_strdup(str);
		else
			room->name = NULL;
		room->tab  = NULL;
		room->dist = 0;
	}
	return (room);
}

t_lemroom		**newtabroom(int i)
{
	t_lemroom	**tabroom;

	if (!i)
		return (NULL);
	tabroom = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + 1));
	if (tabroom)
		tabroom[i] = NULL;
	return (tabroom);
}


int			tabroomlen(t_lemroom **tabroom)
{
	int		i;

	i = 0;
	while (tabroom && tabroom[i])
		i++;
	return (i);
}

void				puttabroom(t_lemroom **tabroom)
{
	int				i;

	i = 0;
	while (tabroom && tabroom[i])
	{
		ft_putstr((tabroom[i])->name);
		ft_putstr(" ");
		i++;
	}
}

void		tabroomcpy(t_lemroom **tabroom, t_lemroom **tabroom1, t_lemroom **tabroom2)
{
	int		i;

	i = 0;
	while (tabroom && tabroom[i])
	{
		tabroom2[i] = tabroom[i];
		i++;
	}
	while (tabroom1 && tabroom1[i])
	{
		tabroom2[i] = tabroom1[i];
		i++;
	}
}

int					lis(t_lemroom **tabroom, char *str)
{
	int				i;

	i = 0;
	while (tabroom && tabroom[i])
	{
		if (!ft_strcmp((tabroom[i])->name, str))
			return (i);
		i++;
	}
	return (0);
}

t_lemroom		**recupfirstroom(t_lemroom *room, t_lem *lem, t_lemroom **tabroom)
{
	t_lemlist	*list = NULL;
	int			i;

	i = 0;
	if (!ft_strcmp(room->name, lem->end))
		return (NULL);
	list = lem->tab[hashcode(room->name)];
	if (is(list, lem))
	{
		room->tab = newtabroom(1);
		(room->tab)[0] = newroom(lem->end);
		puttabroom(room->tab);
		return (NULL);
	}
	i = ft_lemlistlen(list);
	room->tab = newtabroom(i);
	i = 0;
	while (list && room && room->tab)
	{
		if (list->str && ft_strcmp(list->str, lem->start) && ft_strcmp(list->str, room->name))
		{
			if ((lem->tab)[hashcode(list->str)] && !lis(tabroom, list->str))
			{
				(room->tab)[i] = newroom(list->str);
				i++;
			}
		} 
		list = list->next;
		(room->tab)[i] = NULL;
	}
	puttabroom(room->tab);
	ft_putendl(NULL);
	lem->tab[hashcode(room->name)] = NULL;
	return (room->tab);
}

t_lemroom	**merge(t_lemroom **tabroom, t_lemroom **tabroom1)
{
	int			i;
	int			j;
	t_lemroom	**tabroom2;

	if(!tabroom1)
		return (tabroom);
	if(!tabroom)
		return (tabroom1);
	i = tabroomlen(tabroom);
	j = tabroomlen(tabroom1);
	tabroom2 = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + j + 1));
	tabroom2[i + j] = NULL;
	tabroomcpy(tabroom, tabroom1, tabroom2);
	return (tabroom2);
}

t_lemroom	**recupnextroom(t_lemroom **tabroom, t_lem *lem)
{
	t_lemroom	**tabroom1 = NULL;
	t_lemroom	**tabroom2 = NULL;
	int	i;

	i = 0;
	while (tabroom && tabroom[i])
	{
		if (ft_strcmp((tabroom[i])->name, lem->end))
		{
			tabroom2 = recupfirstroom(tabroom[i], lem, tabroom);
			tabroom1 = merge(tabroom1, tabroom2);
		}
		i++;
	}
	i = 0;
	while (tabroom && tabroom[i])
	{
		if (ft_strcmp((tabroom[i])->name, lem->end))
		lem->tab[hashcode((tabroom[i])->name)] = NULL;
		i++;
	}
	return (tabroom1);
}