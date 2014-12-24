/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaddow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 15:08:18 by msarr             #+#    #+#             */
/*   Updated: 2014/12/24 17:36:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect		ray_shad(t_ray *ray, t_env *env, t_scene *scene, t_vect point, t_vect norm)
{
	t_vect		amb;
	t_tracing	trac;
	t_light 	*light;
	double		dist;
	t_vect		l_vect;
	t_ray		l_ray;
	int 		tmp;

	light = env->light;
	amb = new(0, 0, 0);
	while(light)
	{
		// Calc the vec (normalized) going from the light to the intersection point
		l_vect = sub(point, light->pos);
		dist = length(l_vect);
		l_vect = normal(l_vect);
		l_ray.orig = light->pos;
		l_ray.dir = l_vect;
		trac = ray_once(&l_ray, env);
		(void)ray;
		(void)norm;
		if (trac.scene == NULL && trac.dist > dist)
		{
			tmp = 1;
			if ((unsigned short int) (amb.x + tmp * light->color.x*light->i * scene->color.x) > scene->color.x)
				amb.x = scene->color.x *light->i;
			else
				amb.x += tmp*light->color.x*scene->color.x;
			if ((unsigned short int) (amb.z + tmp * light->color.z*light->i * scene->color.z) > scene->color.z)
				amb.z = scene->color.z *light->i;
			else
				amb.z += tmp*light->color.z*scene->color.z;
			if ((unsigned short int) (amb.y + tmp * light->color.y *light->i * scene->color.y) > scene->color.y)
				amb.y = scene->color.y*light->i;
			else
				amb.y += tmp * light->color.y * scene->color.y;
			printf("%lf %lf %lf ", amb.x, amb.y, amb.z);
		}
		light = light->next;
		if (!light)
			printf("\n");	
	}
	return (amb);
}
