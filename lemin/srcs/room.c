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
		ft_putcolorstr(room->name, RED);
		ft_putcolorstr(" : ", RED);
		while (room->tab && (room->tab)[i])
		{
			ft_putstr(((room->tab)[i])->name);
			ft_putstr(" ");
			i++;
		}
		ft_putendl(NULL);
	}
}

void		tabroomcpy(t_lemroom **tab, t_lemroom **tab1, t_lemroom **tab2)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		tab2[i] = tab[i];
		i++;
	}
	while (tab1 && tab1[i])
	{
		tab2[i] = tab1[i];
		i++;
	}
}

t_lemroom		*allocroom(char *str)
{
	t_lemroom	*room;

	room = (t_lemroom *)malloc(sizeof(t_lemroom));
	if (room)
	{
		room->name = ft_strdup(str);
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

t_lemroom		*newroom(char *str, t_lem *lem)
{
	t_lemroom	*room;
	t_lemlist	*list;
	int			i;

	list = (lem->tab)[hashcode(str)];
	if (!list)
		return (NULL);
	list = is(list, lem);
	i = ft_lemlistlen(list, str, lem->start);
	room = allocroom(str);
	if (room && !ft_strcmp(room->name, lem->end))
	{
		room->tab = NULL;
		return (room);
	}
	else
	{
		room->tab = alloctabroom(i);
		listtotab(list, lem, room, i);
	}
	return (room);
}

t_lemroom		*newendroom(char *str, t_lem *lem)
{
	t_lemroom	*room;
	t_lemlist	*list;
	int			i;

	list = (lem->tab)[hashcode(str)];
	if (!list)
		return (NULL);
	i = ft_lemlistlen(list, str, str);
	room = allocroom(str);
	if (room)
	{
		room->tab = alloctabroom(i);
		listtotab(list, lem, room, i);
	}
	return (room);
}