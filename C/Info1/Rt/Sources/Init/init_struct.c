/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:47:58 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 16:48:00 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

void	init_k(t_k *k)
{
	k->nb = 0;
	k->k = 0.0;
	k->type = 0;
	k->ind = 0.0;
	k->brill = 0.0;
	init_color(&k->color);
}

void	init_vect(t_vect *vect)
{
	vect->v_x = 0.0;
	vect->v_y = 0.0;
	vect->v_z = 0.0;
	vect->n_x = 0.0;
	vect->n_y = 0.0;
	vect->n_z = 0.0;
}

void	init_utils(t_utils *utils)
{
	utils->spot = NULL;
	init_vect(&utils->norm);
	init_vect(&utils->vect);
	init_coord(&utils->coord);
}

void	init_spot(t_spot *spot)
{
	init_coord(&spot->coord);
	init_color(&spot->color);
}

void	init_objet(t_objet *obj)
{
	obj->nb = 0;
	obj->type = 0;
	obj->size = 0.0;
	obj->brill = 0.0;
	obj->middle = 0.0;
	obj->next = NULL;
	init_rot(&obj->rot);
	init_coord(&obj->coord);
	init_color(&obj->color);
	init_color(&obj->pm_color);
	init_color(&obj->ps_color);
}
