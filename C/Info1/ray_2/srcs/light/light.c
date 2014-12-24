/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:18:28 by msarr             #+#    #+#             */
/*   Updated: 2014/12/20 14:15:24 by msarr            ###   ########.fr       */
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
	put_vect("light", lightVector);
	angle = dot(norm, negate(lightVector));
	printf("angle %f\n", angle);            	
	/*if (angle <= 0)
		finalColor = new(0.0f, 0.0f, 0.0f);
	else*/
		finalColor = mult2(mult2(light->color, cos(angle)), scene->diff);
	put_vect("diff" ,finalColor);
	return finalColor;
}

double			light_spec(t_light *light, t_vect light_dir, t_vect norm, t_vect ray_dir, double spec)
{
	double		high;
	t_vect		v;
	t_vect		r;
	double		i;
	double		s;


	high = dot(norm, light_dir);
	v = negate(ray_dir);
	r = sub(light_dir, mult2(norm, high * 2.0));
	i = dot(v, r);
	if (i < 0)
		return (0);
	s = pow(i, spec) * KS_CONST * light->i;
	return (s);
}
