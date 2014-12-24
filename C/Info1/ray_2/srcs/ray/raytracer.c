/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 01:29:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/24 17:06:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static t_vect	ray_recursive(t_ray *ray, t_env *env, size_t depth)
{
	t_tracing 	hit;
	t_vect	 	colis;
	t_vect	 	norm;

	hit = ray_once(ray, env);
	if (hit.scene == NULL)
		return (COLOR_BLACK);
	(void)depth;
	//return(hit.scene->color);
	colis = add(mult2(ray->dir, hit.dist), ray->orig);
	//put_vect("colis", colis);
	norm = divi(sub(colis, hit.scene->pos), hit.scene->size);
	return(ray_shad(ray, env, hit.scene, colis, norm));
}


t_ray        new_ray(t_vect orig, t_vect dir)
{
	t_ray   r;

	r.orig = orig;
	r.dir = dir;
	return r;
}

t_ray		pixel(t_cam *c, double x, double y)
{
	return new_ray(c->pos, normal(sub(sub(add(c->upleft, mult2(c->upright, x)), mult2(c->up, y)), c->pos)));
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
	dist = MAX_DIST;
	clos.dist = MAX_DIST;
	hit = 0;
	scene = env->scene;
	while (scene)
	{
		hit = inter_center(ray, scene, &dist);
		if (hit && dist > EPSILON && dist < clos.dist)
		{
			clos.dist = dist;
			clos.scene = scene;
		}
		scene = scene->next; 
	}
	return (clos);
}
