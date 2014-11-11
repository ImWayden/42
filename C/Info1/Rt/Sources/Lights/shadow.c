/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:51:44 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 16:51:46 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

double	calc_shad(t_objet p, t_utils l, int type)
{
	double	k;

	k = -1.0;
	if (type == PLAN)
		k = inter_plan(l, &p);
	else if (type == SPHERE)
		k = inter_sphere(l, &p);
	else if (type == CYLINDRE)
		k = inter_cylindre(l, &p);
	else if (type == CONE)
		k = inter_cone(l, &p);
	else if (type == PARABOLOIDE)
		k = inter_paraboloide(l, &p);
	else if (type == HYPERBOLOIDE)
		k = inter_hyperboloide(l, &p);
	return (k);
}

void	init_shadow(t_utils *l, t_objet p)
{
	l->norme = 0.0;
	l->norm.n_x = 0.0;
	l->norm.n_y = 0.0;
	l->norm.n_z = 0.0;
	l->vect.v_x = l->spot->coord.x - p.coord.x;
	l->vect.v_y = l->spot->coord.y - p.coord.y;
	l->vect.v_z = l->spot->coord.z - p.coord.z;
	l->coord.x = p.coord.x;
	l->coord.y = p.coord.y;
	l->coord.z = p.coord.z;
}

void	lower_color(t_k **k)
{
	(*k)->color.red = (*k)->color.red >> 1;
	(*k)->color.blue = (*k)->color.blue >> 1;
	(*k)->color.green = (*k)->color.green >> 1;
}

double	right_shad(t_objet *p, t_objet *tmp, t_objet *obj, t_utils l)
{
	double	k;

	k = -1.0;
	p->size = tmp->size;
	if (obj != tmp)
	{
		trans_inv(&l, tmp, 0);
		obj_rot(&l, tmp, -1, 1);
		k = calc_shad(*p, l, tmp->type);
		obj_rot(&l, tmp, 1, 1);
		trans_nor(&l, tmp, 0);
	}
	return (k);
}

t_k		*shadow(t_param *param, t_objet *obj, t_k *k, t_utils *utils)
{
	t_objet	p;
	t_objet	*tmp;
	t_utils l;
	double	k_shad;

	k_shad = -1.0;
	calc_coord(k, &p, utils);
	l.spot = param->spot;
	while (l.spot)
	{
		init_shadow(&l, p);
		tmp = param->objet;
		while (tmp != NULL)
		{
			k_shad = right_shad(&p, tmp, obj, l);
			if (k_shad >= 0.0 && k_shad <= 1.0)
				lower_color(&k);
			tmp = tmp->next;
		}
		l.spot = l.spot->next;
	}
	return (k);
}
