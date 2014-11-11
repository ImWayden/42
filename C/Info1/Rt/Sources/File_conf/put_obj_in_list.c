/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_obj_in_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:47:13 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 17:35:08 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

void	fill_obj(t_objet **new, t_objet elem)
{
	(*new)->type = elem.type;
	(*new)->coord.x = elem.coord.x;
	(*new)->coord.y = elem.coord.y;
	(*new)->coord.z = elem.coord.z;
	(*new)->color.red = elem.color.red;
	(*new)->color.green = elem.color.green;
	(*new)->color.blue = elem.color.blue;
	(*new)->rot.rot_x = elem.rot.rot_x;
	(*new)->rot.rot_y = elem.rot.rot_y;
	(*new)->rot.rot_z = elem.rot.rot_z;
	(*new)->brill = elem.brill;
	(*new)->middle = elem.middle;
	(*new)->size = elem.size;
	(*new)->pm_color.red = elem.pm_color.red;
	(*new)->pm_color.green = elem.pm_color.green;
	(*new)->pm_color.blue = elem.pm_color.blue;
	(*new)->ps_color.red = elem.ps_color.red;
	(*new)->ps_color.green = elem.ps_color.green;
	(*new)->ps_color.blue = elem.ps_color.blue;
	(*new)->perturb = elem.perturb;
	(*new)->next = NULL;
}

void	put_obj_in_list(t_objet **obj, t_objet elem)
{
	t_objet	*tmp;
	t_objet	*new;

	new = malloc(sizeof(*new));
	if (!new)
		exit(0);
	fill_obj(&new, elem);
	if (*obj == NULL)
		*obj = new;
	else
	{
		tmp = *obj;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	put_spot_in_list(t_spot **spot, t_spot elem)
{
	t_spot	*tmp;
	t_spot	*new;

	new = malloc(sizeof(*new));
	if (!new)
		exit(0);
	new->coord.x = elem.coord.x;
	new->coord.y = elem.coord.y;
	new->coord.z = elem.coord.z;
	new->color.red = elem.color.red;
	new->color.green = elem.color.green;
	new->color.blue = elem.color.blue;
	new->next = NULL;
	if (*spot == NULL)
		*spot = new;
	else
	{
		tmp = *spot;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
