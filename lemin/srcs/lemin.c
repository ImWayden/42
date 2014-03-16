/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/03/13 14:16:15 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			epure(t_lemroom *room, t_lem *lem)
{
	int				i;

	i = 1;
	if (room && room->tab && room->tab[0])
		epure(room->tab[0], lem);
	while (room && room->tab && room->tab[i])
	{
		lem->tab[hash((room->tab[i])->name)] = room->tab[i];
		room->tab[i] = NULL;
		i++;
	}
}

void					moove(t_lemroom **tab, int k)
{
	int				i;

	i = tabroomlen(tab)  - 1;
	if (tab && tab[i] && tab[k])
		ft_swap((void **)&(tab[i]), (void **)&(tab[k]));
	delroom(&tab[i]);
}