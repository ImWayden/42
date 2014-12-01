/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 22:34:01 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 11:29:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

int				sphere_inter(t_ray *ray, t_scene *sphere, double *dist)
{
	double		a;
	t_vect		ro_sc;
	double		b;
	double		c;
	double		disc;
	double		distSqrt;
	double		q;
	double		t0;
	double		t1;
	double		swap;

	a = dot(ray->dir, ray->dir);
	ro_sc = sub(ray->orig, sphere->pos);
	b = 2.0 * dot(ray->dir, ro_sc);
	c = dot(ro_sc, ro_sc) - SQUARE(sphere->size);
	disc = SQUARE(b) - 4 * a * c;
	if (disc < 0)
		return 0;
	distSqrt = sqrt(disc);
	q = b < 0.0 ? (-b - distSqrt) / 2.0 : (-b + distSqrt) / 2.0;
	t0 = q / a;
	t1 = c / q;
	if (t0 > t1)
	{
		swap = t0;
		t0 = t1;
		t1 = swap;
	}
	if (t1 < 0)
		return 0;
	else if(t0 < 0)
		*dist = t1;
	else
		*dist = t0;
	return 1;
}
