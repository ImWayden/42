/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:18:28 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 11:30:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect			light_dir(t_light *light, t_vect point)
{
	return (unit(sub(point, light->pos)));
}

t_vect			light_diff(t_light *light, t_scene *scene, t_vect point, double dist)
{
	t_vect		lightVector;
	float		angle;
	t_vect		finalColor;
                     
	lightVector = normal(sub(point, light->pos));
	angle = dot(get_norm(scene, point), negate(lightVector));
	if (angle <= 0)
		finalColor = new(0.0f, 0.0f, 0.0f);
	else
		finalColor = mult2(mult2(mult2(light->color, (MAX_V_DIST - dist) / MAX_V_DIST* light->i), angle), scene->diff);
	return finalColor;
}

t_vect			light_spec(t_light *light, t_ray *ray, t_scene *scene, t_vect point, double dist)
{
	t_vect		lightVector;
	t_vect		v;
	t_vect		r;
	float		angle;
	t_vect		finalColor;

	lightVector = normal(sub(point, light->pos));
	v = negate(ray->dir);
	r = reflected_ray(&lightVector, scene, point);
	angle = dot(v, r);
	if (angle < 0)
		finalColor = new(0.0f, 0.0f, 0.0f);
	else
		finalColor = mult2(mult2(mult2(light->color, (MAX_V_DIST - dist) / MAX_V_DIST * light->i), angle), scene->spec* KS_CONST);
		//finalColor = mult2(light->color, pow(angle, scene->spec) * KS_CONST);
	return (finalColor);
}
