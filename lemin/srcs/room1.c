/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:42:44 by msarr             #+#    #+#             */
/*   Updated: 2014/03/10 15:42:47 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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
			//tabroom2 = recupfirstroom(tabroom[i], lem, tabroom);
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
