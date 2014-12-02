/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 01:29:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 11:58:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static t_vect	ray_recursive(t_ray *ray, t_env *env, size_t depth)
{
	t_tracing 	hit;
	t_shading 	shad;
	t_vect	 	color;
	t_vect	 	r_color;
	t_vect	 	colis;
	t_ray		reflect;

	hit = ray_once(ray, env);
	if (hit.scene == NULL)
		return (env->back_color);
	color = hit.scene->color;
	colis = add(mult2(ray->dir, hit.dist), ray->orig);
	if (hit.scene->reflect > 0.0 && depth > 0)
	{
		reflect = ray_reflect(ray, hit.scene, colis);
		if (hit.scene->reflect > 0)
			reflect = ray_addnoise(&reflect, hit.scene->reflect);
		r_color = ray_recursive(&reflect, env, depth - 1);
		r_color = color_blend(r_color, hit.scene->reflect, color);
	}
	shad = ray_shad(ray, env, hit.scene, colis);    
	color = get_color(color, shad, env->amb);
	color = mult2(color, (MAX_VISIBLE_DISTANCE - hit.dist) / MAX_VISIBLE_DISTANCE);
	return (color);
}

t_ray        new_ray(t_vect orig, t_vect dir)
{
	t_ray   r;

	r.orig = orig;
	r.dir = dir;
	return r;
}

t_ray		pixel(t_cam *c, size_t x, size_t y)
{
	t_vect	dir;

	dir.z = cam->focal;
	dir.z = cam->;
	u_r = new(x, y, 0);
	return (new_ray(c->pos, u_r));
}

t_vect		raytrace(t_ray *ray, t_env *env)
{
	return ray_recursive(ray, env, MAX_RECURSION_DEPTH);
}

t_tracing		ray_once(t_ray *ray, t_env *env)
{
	t_tracing 	clos;
	double 		dist;
	int 		hit;
	t_scene		*scene;

	clos.scene = NULL;
	clos.dist = 1.0 / 0.0;
	dist = 1.0 / 0.0f;
	hit = 0;
	scene = env->scene;
	while (scene)
	{
		hit = inter_center(ray, scene, &dist);
		if (hit && dist < clos.dist && dist > EPSILON)
		{
			clos.dist = dist;
			clos.scene = scene;
		}
		scene = scene->next; 
	}
	return (clos);
}
