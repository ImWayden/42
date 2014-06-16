/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:56:02 by msarr             #+#    #+#             */
/*   Updated: 2014/06/17 01:20:27 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lem				*newlem(void)
{
	t_lem			*pars;
	int				i;

	if ((pars = (t_lem *)malloc(sizeof(t_lem))))
	{
		pars->start = NULL;
		pars->end = NULL;
		pars->j = 0;
		i = 0;
		while (pars && pars->tab && i < 1000)
		{
			pars->tab[i] = NULL;
			i++;
		}
	}
	else
		perror("newlem function :");
	return (pars);
}

void				dellem(t_lem **lem)
{
	t_lem 			*tmp;
	int 			i;

	i = 0;
	tmp = *lem;
	ft_memdel((void **)&(tmp->end));
	while ((*lem)->tab[i])
		delroom(&(*lem)->tab[i++]);
	ft_memdel((void **)&(tmp->start));
	ft_memdel((void **)&tmp);
	tmp = NULL;
}

void					moove(t_lemroom **tab, int k)
{
	int				i;

	i = tabroomlen(tab)  - 1;
	if (tab && tab[i] && tab[k])
		ft_swap((void **)&(tab[i]), (void **)&(tab[k]));
	delroom(&tab[i + 1]);
	delroom(&tab[i]);
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
