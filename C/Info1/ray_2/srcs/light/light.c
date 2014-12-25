/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:18:28 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 19:11:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect			light_dir(t_light *light, t_vect point)
{
	return (unit(sub(point, light->pos)));
}

t_vect			light_diff(t_light *light, t_vect norm, t_scene *scene, t_vect point)
{
	t_vect		lightVector;
	float		angle;
	t_vect		finalColor;
                     
	lightVector = normal(sub(point, light->pos));
	angle = dot(norm, negate(lightVector));
	if (angle <= 0)
		finalColor = new(0.0f, 0.0f, 0.0f);
	else
		finalColor = mult2(mult2(light->color, angle), scene->diff);
	return finalColor;
}

t_vect			light_spec(t_light *light, t_vect norm, t_scene *scene, t_vect point, t_ray *ray)
{
	t_vect		lightVector;
	t_vect		v;
	t_vect		r;
	float		angle;
	float		high;
	t_vect		finalColor;

	lightVector = normal(sub(point, light->pos));
	v = negate(ray->dir);
	high = dot(norm, negate(lightVector));
	r = sub(lightVector, mult2(norm, high * 2.0));
	angle = dot(v, r);
	if (angle < 0)
		finalColor = new(0.0f, 0.0f, 0.0f);
	else
		finalColor = mult2(mult2(light->color, angle), scene->spec* KS_CONST);
		//finalColor = mult2(light->color, pow(angle, scene->spec) * KS_CONST);
	return (finalColor);
}
