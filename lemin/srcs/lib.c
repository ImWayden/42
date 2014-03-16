/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:56:02 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 14:56:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lem				*newlem(void)
{
	t_lem			*pars;
	int				i;

	pars = (t_lem *)malloc(sizeof(t_lem));
	pars->start = NULL;
	pars->end = NULL;
	i = 0;
	while (((pars->tab)[i] = NULL))
		i++;
	return(pars);
}

void				dellem(t_lem **lem)
{
	t_lem 			*tmp;
	int 			i;

	i = 0;
	tmp = *lem;
	while(tmp->tab && i < 1000)
	{
		delroom(&(tmp->tab[i]));
		i++;
	}
	ft_memdel((void **)&(tmp->end));
	ft_memdel((void **)&(tmp->start));
	ft_memdel((void **)&tmp);
	tmp = NULL;
}

int						istab(t_lemroom **room, t_lem *lem)
{
	int					i;

	i = 0;
	while (room && room[i])
	{
		if (!ft_strcmp((room[i])->name, lem->end))
			return (i);
		i++;
	}
	return (-1);
}



void				sort(t_lemroom **tab)
{
	int				i;
	int				j;
	t_lemroom		*room;

	i = 0;
	while (tab && tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if ((tab[i])->dist > (tab[j])->dist)
			{
				room = tab[i];
				tab[i] = tab[j];
				tab[j] = room;
			}
			j++;
		}
		i++;
	}
}
