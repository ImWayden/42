/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 22:34:01 by msarr             #+#    #+#             */
/*   Updated: 2014/11/29 14:02:02 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect	 	*normal_at(t_sphere *sphere, float px,float py,float pz)
{
	t_vect	a;
	float	v;

	v = 1.0f / sphere->radius;
	a.x = px - sphere->vect.x;
	a.y = py - sphere->vect.y;
	a.z = pz - sphere->vect.z;
	a.x *= v;
	a.y *= v;
	a.z *= v;
	return (new_vect(a));
}

t_vect		 *ray_sphere(t_sphere *sphere, float x1,float y1,float z1,float x2,float y2,float z2, int *ret)
{
	t_vect 		p;
	t_vect		v;
	t_vect		e;
	float		dist;
	float		disc;
	float		i;
	//assume the intersection failed
	*ret = -1;
	v.x = x2 - x1;
	v.y = y2 - y1;
	v.z = z2 - z1;
	e.x = sphere->vect.x - x1;
	e.y = sphere->vect.y - y1;
	e.z = sphere->vect.z - z1;
	if ((e.x * v.x + e.y * v.y + e.z * v.z ) <=0)
		return (NULL);
	dist = 1.0f / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x *= dist;
	v.y *= dist;
	v.z *= dist;
	i = e.x * v.x + e.y * v.y + e.z * v.z;
	disc = sphere->radius * sphere->radius -(e.x * e.x + e.y * e.y + e.z * e.z - i * i);
	if(disc >= 0)
	{
		disc = sqrt(disc);
		p.x = x1 + (i - disc) * v.x;
		p.y = y1 + (i - disc) * v.y;
		p.z = z1 + (i - disc) * v.z;
		*ret = 1;
	}
	return (new_vect(p));
}
