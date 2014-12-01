/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaddow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 15:08:18 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 02:29:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_shading		ray_shad(t_ray *ray, t_env *env, t_scene *scene, t_vect point)
{
	t_light 	*light;
	t_shading	shad;
	t_tracing	trac;
	double		dist;
	t_vect		dir;
	t_vect		norm;
	t_ray		new;

	shad.diff = 0.0;
	shad.spec = 0.0;
	new.orig = point;
	light = env->light;
	while(light)
	{
		dir = light_dir(light, point);
		new.dir = negate(dir);
		dist = length(sub(light->pos, point));
		trac = ray_once(&new, env);
		if (trac.scene == NULL || trac.dist > dist)
		{
			norm = get_norm(scene, point);
			shad.diff += light_diff(light, dir, norm);
			shad.spec += light_spec(light, dir,	norm, ray->dir, scene->spec);
		}
		light = light->next;
	}
	return (shad);
}
