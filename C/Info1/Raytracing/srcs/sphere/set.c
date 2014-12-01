/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 22:37:55 by msarr             #+#    #+#             */
/*   Updated: 2014/11/29 01:11:47 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

void		set_pos(t_vect *vect, float x, float y, float z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

void		set_radius(t_sphere *sphere, float r)
{
	sphere->radius = r;
}

void		setintensity(t_env *env, float pi)
{
	env->light.i = pi;
}


void		set_color(t_vect *color, int r, int g, int b)
{
	color->x = r;
	color->y = g;
	color->z = b;
}
