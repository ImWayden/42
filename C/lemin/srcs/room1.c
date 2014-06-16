/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:42:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/16 23:08:12 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_lemroom		**alloctabroom(int i)
{
	t_lemroom	**tab;

	if ((tab = (t_lemroom **)malloc(sizeof(t_lemroom *) * (i + 1))))
		tab[i] = NULL;
	i = 0;
	while (tab && tab[i])
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
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

t_lemroom	**merge(t_lemroom ***tabroom, t_lemroom **tabroom1)
{
	int			i;
	int			j;
	t_lemroom	**tabroom2;

	if (!tabroom1)
		return (*tabroom);
	if (!(*tabroom))
		return (tabroom1);
	i = tabroomlen(*tabroom);
	j = tabroomlen(tabroom1);
	tabroom2 = alloctabroom(i + j);
	tabroomcpy(*tabroom, tabroom1, tabroom2);
	return (tabroom2);
}
