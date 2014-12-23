/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 16:13:32 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 02:40:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_ray		ray_reflect(t_ray *ray, t_scene *scene, t_vect point)
{
	t_vect	norm;
	double	c;
	t_vect	r;

	norm = get_norm(scene, point);
	c = -dot(norm, ray->dir);
	r = add(ray->dir, mult2(norm, 2 * c));
	return (new_ray(point, r));
}