/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/18 13:38:56 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				get_room(char *str, t_lem *pars, int flag)
{
	char			**tab;

	if ((tab = ft_strsplit(str, ' ')) && tab[0])
	{
		if (flag == 1)
		{
			pars->lem_start = allocroom(tab[0]);
			pars->start = ft_strdup(tab[0]);
		}
		else if (flag == 2)
		{
			pars->lem_end = allocroom(tab[0]);
			pars->end = ft_strdup(tab[0]);
		}
		else
			pars->tab[hash(tab[0])] = allocroom(tab[0]);
		deltab(&tab);
		return (1);
	}
	return (0);
}

int				get_tab(char *str, t_lem *pars)
{
	char			**tab;

	if ((tab = ft_strsplit(str, '-')) && tab[0] && tab[1])
	{
		if (!ft_strcmp(pars->start, tab[0]))
			addroom(pars->lem_start, tab[1]);
		if (ft_strcmp(pars->end, tab[0]) && ft_strcmp(pars->start, tab[1]))
			addroom(pars->tab[hash(tab[0])], tab[1]);
		if (!ft_strcmp(pars->start, tab[1]))
			addroom(pars->lem_start, tab[0]);
		if (ft_strcmp(pars->end, tab[1]) && ft_strcmp(pars->start, tab[0]))
			addroom(pars->tab[hash(tab[1])], tab[0]);
		deltab(&tab);
		return (1);
	}
	return (0);
}

int				get_start_end(t_getline *list, t_lem *pars)
{
	while (list)
	{
		if (!ft_strcmp(list->str, "##start"))
			get_room(list->next->str, pars, 1);
		if (!ft_strcmp(list->str, "##end"))
			get_room(list->next->str, pars, 2);
		list = list->next;
	}
	if (pars->lem_start && pars->lem_end)
		return (1);
	return (0);
}
