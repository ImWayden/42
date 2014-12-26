/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 16:13:32 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 01:19:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect		reflected_ray(t_vect *dir, t_scene *scene, t_vect point)
{
	t_vect	norm;
	double	high;
	t_vect	r;

	norm = get_norm(scene, point);
	high = dot(norm, negate(*dir));
	r = sub(*dir, mult2(norm, high * 2.0));
	return (normal(r));
}

t_ray		ray_reflect(t_vect *dir, t_scene *scene, t_vect point)
{
	t_vect	r;

	r = reflected_ray(dir, scene, point);
	return (new_ray(point, r));
}