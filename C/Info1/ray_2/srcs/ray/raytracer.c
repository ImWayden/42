/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 01:29:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 19:44:12 by msarr            ###   ########.fr       */
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
	//return(hit.scene->color);
	(void)depth;
	colis = add(mult2(ray->dir, hit.dist), ray->orig);
	norm = get_norm(hit.scene, colis);
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

int 			in_dir(t_ray *ray, t_scene *s)
{
	if (ray->dir.x < 0 && s->pos.x > ray->orig.x)
		return (0);
	if (ray->dir.x > 0 && s->pos.x < ray->orig.x)
		return (0);
	if (ray->dir.x == 0 && s->pos.x != ray->orig.x)
		return (0);
	return(1);
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
