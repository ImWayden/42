/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:29:04 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:39:01 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

int		g_assign;

int		get_new_assign(void)
{
	while (g_assign % 10 != 0)
		g_assign--;
	return (g_assign);
}

void	other_assign_value(t_objet **elem, char *str)
{
	if (g_assign == 71)
		(*elem)->middle = atof(str);
	if (g_assign == 92)
		(*elem)->pm_color.red = (short)(atoi(str));
	if (g_assign == 93)
		(*elem)->pm_color.green = (short)(atoi(str));
	if (g_assign == 94)
		(*elem)->pm_color.blue = (short)(atoi(str));
	if (g_assign == 95)
		(*elem)->ps_color.red = (short)(atoi(str));
	if (g_assign == 96)
		(*elem)->ps_color.green = (short)(atoi(str));
	if (g_assign == 97)
		(*elem)->ps_color.blue = (short)(atoi(str));
	if (g_assign == 101)
		(*elem)->perturb = atoi(str);
}

void	assign_value(t_objet **elem, char *str)
{
	if (g_assign == 11)
		(*elem)->coord.x = atof(str);
	else if (g_assign == 12)
		(*elem)->coord.y = atof(str);
	else if (g_assign == 13)
		(*elem)->coord.z = atof(str);
	else if (g_assign == 21)
		(*elem)->color.red = (short)(atoi(str));
	else if (g_assign == 22)
		(*elem)->color.green = (short)(atoi(str));
	else if (g_assign == 23)
		(*elem)->color.blue = (short)(atoi(str));
	else if (g_assign == 31)
		(*elem)->rot.rot_x = atof(str);
	else if (g_assign == 32)
		(*elem)->rot.rot_y = atof(str);
	else if (g_assign == 33)
		(*elem)->rot.rot_z = atof(str);
	else if (g_assign == 41)
		(*elem)->size = atof(str);
	else if (g_assign == 51)
		(*elem)->brill = atof(str);
	else
		other_assign_value(elem, str);
}

void	call_get_elem_obj(t_objet *elem, char **tab, int *i, int f)
{
	elem->type = f;
	elem = get_elem_obj(elem, tab, i, 1);
}

t_objet	*get_one_obj(t_objet *obj, char	**tab, int *i)
{
	t_objet	elem;

	(*i)++;
	init_objet(&elem);
	while (tab[*i] != NULL && ft_strcmp(tab[*i], "<SPOT>") != 0)
	{
		if (ft_strcmp(tab[*i], "<PLAN>") == 0)
			call_get_elem_obj(&elem, tab, i, PLAN);
		else if (ft_strcmp(tab[*i], "<SPHERE>") == 0)
			call_get_elem_obj(&elem, tab, i, SPHERE);
		else if (ft_strcmp(tab[*i], "<CYLINDRE>") == 0)
			call_get_elem_obj(&elem, tab, i, CYLINDRE);
		else if (ft_strcmp(tab[*i], "<CONE>") == 0)
			call_get_elem_obj(&elem, tab, i, CONE);
		else if (ft_strcmp(tab[*i], "<PARABOLOIDE>") == 0)
			call_get_elem_obj(&elem, tab, i, PARABOLOIDE);
		else if (ft_strcmp(tab[*i], "<HYPERBOLOIDE>") == 0)
			call_get_elem_obj(&elem, tab, i, HYPERBOLOIDE);
		put_obj_in_list(&obj, elem);
	}
	g_assign = 0;
	return (obj);
}
