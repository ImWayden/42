/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/17 01:21:09 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				get_room(char *str, t_lem *pars)
{
	char			**tab;

	if ((tab = ft_strsplit(str, ' ') && tab[0])
	{
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
		if (ft_strcmp(pars->end, tab[0]));
		addroom(pars->tab[hash(tab[0])], tab[1]);
		addroom(pars->tab[hash(tab[1])], tab[0]);
		deltab(&tab);
		return (1);
	}
	return (0);
}

int					get_start_end(t_getline *list, t_lem *pars)
{
	while (list)
	{
		if (!ft_strcmp(list->str, "##start"))
			pars->start = ft_strdup(list->next->str);
		if (!ft_strcmp(list->str, "##end"))
			pars->end = ft_strdup(list->next->str);
		list = list->next;
	}
	if (pars->start && pars->end)
		return (1);
	return (0);
}