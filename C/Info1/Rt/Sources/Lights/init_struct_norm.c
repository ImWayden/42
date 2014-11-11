/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:50:51 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 17:49:13 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

void	init_new_color(t_k *k)
{
	k->color.new_red = 0.0;
	k->color.new_blue = 0.0;
	k->color.new_green = 0.0;
}

void	init_distance(t_spot *spot, t_utils *l, t_objet obj3)
{
	l->coord.x = 0.0;
	l->coord.y = 0.0;
	l->coord.z = 0.0;
	l->vect.v_x = spot->coord.x - obj3.coord.x;
	l->vect.v_y = spot->coord.y - obj3.coord.y;
	l->vect.v_z = spot->coord.z - obj3.coord.z;
}

int		prod_scal(t_utils *l, t_utils *utils)
{
	double	tmpx;
	double	tmpy;
	double	tmpz;
	double	tmp;

	tmpx = l->vect.v_x * (utils->vect.n_x - utils->vect.v_x);
	tmpy = l->vect.v_y * (utils->vect.n_y - utils->vect.v_y);
	tmpz = l->vect.v_z * (utils->vect.n_z - utils->vect.v_z);
	tmp = tmpx + tmpy + tmpz;
	if (tmp <= 0.0)
	{
		utils->vect.n_x = -utils->vect.n_x;
		utils->vect.n_y = -utils->vect.n_y;
		utils->vect.n_z = -utils->vect.n_z;
		return (1);
	}
	return (0);
}

t_utils	*init_norm2(t_objet *obj, t_objet obj3, t_utils *utils)
{
	if (obj->type == CONE)
	{
		utils->vect.n_x = obj3.coord.x;
		utils->vect.n_y = obj3.coord.y;
		utils->vect.n_z = (pow(tan(obj3.size), 2) * obj3.coord.z);
	}
	else if (obj->type == PARABOLOIDE)
	{
		utils->vect.n_x = obj3.coord.x;
		utils->vect.n_y = obj3.coord.y;
		utils->vect.n_z = -(obj3.size * M_PI / 180);
	}
	else if (obj->type == HYPERBOLOIDE)
	{
		utils->vect.n_x = obj3.coord.x;
		utils->vect.n_y = obj3.coord.y;
		utils->vect.n_z = -(obj3.size * M_PI / 180) * obj3.coord.z;
	}
	return (utils);
}

t_utils	*init_norm(t_objet *obj, t_objet obj3, t_utils *utils)
{
	if (obj->type == PLAN)
	{
		utils->vect.n_x = 0.0;
		utils->vect.n_y = 0.0;
		utils->vect.n_z = 100.0;
	}
	else if (obj->type == SPHERE)
	{
		utils->vect.n_x = obj3.coord.x;
		utils->vect.n_y = obj3.coord.y;
		utils->vect.n_z = obj3.coord.z;
	}
	else if (obj->type == CYLINDRE)
	{
		utils->vect.n_x = obj3.coord.x;
		utils->vect.n_y = obj3.coord.y;
		utils->vect.n_z = 0.0;
	}
	else
		utils = init_norm2(obj, obj3, utils);
	if (obj->perturb == 1)
		ptb_norm(&utils->vect.n_x, &utils->vect.n_y, &utils->vect.n_z, obj3);
	if (obj->type != SPHERE)
		obj_rot(utils, obj, 1, 2);
	return (utils);
}
