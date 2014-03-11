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

t_lemlist					*is(t_lemlist *list, t_lem *lem)
{
	t_lemlist				*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->str, lem->end))
			return (tmp);
		tmp = tmp->next;
	}
	return (list);
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

void					moove(t_lemroom **tab, int k)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (tab && tab[i])
		i++;
	i--;
	while (tab && tab[j])
	{
		if (tab[j]->dist == k)
		{
			ft_swap((void **)&(tab[i]), (void **)&(tab[j]));
			free(tab[i]);
			tab[i] = NULL;
			i--;
		}
		j++;
	}
}

void				sort(t_lemroom **tab)
{
	int				i;
	int				j;

	i = 0;
	moove(tab, -1);
	while (tab && tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if ((tab[i])->dist > (tab[j])->dist && (tab[j])->dist)
				ft_swap((void **)&(tab[i]), (void **)&(tab[j]));
			if (!(tab[i])->dist)
				ft_swap((void **)&(tab[i]), (void **)&(tab[j]));
			j++;
		}
		i++;
	}
}
