/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:36:23 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:39:32 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

extern int	g_assign;

void	assign_value_spot(t_spot **elem, char *str)
{
	if (g_assign == 11)
		(*elem)->coord.x = ft_atoi(str);
	if (g_assign == 12)
		(*elem)->coord.y = ft_atoi(str);
	if (g_assign == 13)
		(*elem)->coord.z = ft_atoi(str);
	if (g_assign == 21)
		(*elem)->color.red = (short)(ft_atoi(str));
	if (g_assign == 22)
		(*elem)->color.green = (short)(ft_atoi(str));
	if (g_assign == 23)
		(*elem)->color.blue = (short)(ft_atoi(str));
}

void	get_this_spot(t_spot *elem, char **tab, int *i, int flag)
{
	if (flag == 1)
		(*i)++;
	while (tab[*i] != NULL && ft_strcmp(tab[*i], "<OBJ>") != 0
		&& ft_strcmp(tab[*i], "<SPOT>") != 0)
	{
		if (ft_strcmp(tab[*i], "<POS>") == 0)
		{
			g_assign = 10;
			elem = extract_elem_spot(elem, tab, i);
		}
		else if (ft_strcmp(tab[*i], "<COL>") == 0)
		{
			g_assign = 20;
			elem = extract_elem_spot(elem, tab, i);
		}
	}
	g_assign = 0;
}

t_spot	*get_one_spot(t_spot *spot, char **tab, int *i)
{
	t_spot	elem;

	while (tab[*i] != NULL && ft_strcmp(tab[*i], "<OBJ>") != 0)
	{
		if (ft_strcmp(tab[*i], "<SPOT>") == 0)
			get_this_spot(&elem, tab, i, 1);
		put_spot_in_list(&spot, elem);
	}
	return (spot);
}
