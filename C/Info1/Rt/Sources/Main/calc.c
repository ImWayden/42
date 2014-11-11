/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:52:13 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:01:18 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

t_k		fill_closest(t_k *k, t_k closest)
{
	closest.type = k->type;
	closest.nb = k->nb;
	closest.color.red = k->color.red;
	closest.color.green = k->color.green;
	closest.color.blue = k->color.blue;
	closest.k = k->k;
	closest.brill = k->brill;
	return (closest);
}

void	init_utils_eye(t_utils *utils, t_param *param, double x, double y)
{
	utils->coord.x = param->eye_coord.x;
	utils->coord.y = param->eye_coord.y;
	utils->coord.z = param->eye_coord.z;
	utils->eye_rot.rot_x = param->eye_rot.rot_x;
	utils->eye_rot.rot_y = param->eye_rot.rot_y;
	utils->eye_rot.rot_z = param->eye_rot.rot_z;
	utils->vect.v_x = 1000.0;
	utils->vect.v_y = ((WIN_X / 2.000) - x);
	utils->vect.v_z = ((WIN_Y / 2.000) - y);
	utils->spot = param->spot;
	utils->amb = param->amb;
}

t_k		calc(double x, double y, t_param *param, t_k *k)
{
	t_k		closest;
	t_objet	*tmp;
	t_utils	utils;

	k = NULL;
	init_k(&closest);
	init_utils(&utils);
	tmp = param->objet;
	init_utils_eye(&utils, param, x, y);
	obj_rot(&utils, NULL, -1, 0);
	while (tmp != NULL)
	{
		k = search_k(tmp, utils, k, param);
		tmp = tmp->next;
	}
	closest = fill_closest(k, closest);
	if (k)
		free(k);
	return (closest);
}
