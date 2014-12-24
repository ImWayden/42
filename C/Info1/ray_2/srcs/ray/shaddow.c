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

	light = env->light;
	amb = mult2(scene->color, env->amb);
	printf("%lf\n", 1 * 0.2);
	put_vect("amb", amb);
	put_vect("co", scene->color);
	while(light)
	{
		// Calc the vec (normalized) going from the light to the intersection point
		l_vect = sub(point, light->pos);
		dist = length(l_vect);
		printf("dist %lf\n", dist);
		l_vect = normal(l_vect);
		l_ray.orig = light->pos;
		l_ray.dir = l_vect;
		trac = ray_once(&l_ray, env);
		(void)ray;
		if (trac.scene == NULL || trac.dist > dist || trac.scene == scene)
		{
			amb = add(amb, light_diff(light, norm, scene, point));
			printf("%lf %lf %lf ", amb.x, amb.y, amb.z);
		}
		light = light->next;
		if (!light)
			printf("\n");	
	}
	return (amb);
}
