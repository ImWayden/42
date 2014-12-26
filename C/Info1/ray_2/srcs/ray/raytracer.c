/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 01:29:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 11:25:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static t_vect	ray_recursive(t_ray *ray, t_env *env, size_t depth)
{
	t_tracing 	hit;
	t_vect	 	colis;
	t_vect	 	color;
	t_vect	 	r_color;
	t_ray		reflect;

	hit = ray_once(ray, env);
	if (hit.scene == NULL)
		return (COLOR_BLACK);
	colis = add(mult2(ray->dir, hit.dist), ray->orig);
	color = hit.scene->color;
	if (hit.scene->reflect > 0.0 && depth > 0)
	{
		reflect = ray_reflect(&ray->dir, hit.scene, colis);
        r_color = ray_recursive(&reflect, env, depth - 1);
        color = color_blend(r_color, hit.scene->reflect, color);
    }
	color = ray_shad(ray, env, hit.scene, colis, color);
	color = mult2(color, (MAX_V_DIST - hit.dist) / MAX_V_DIST);
    return (color);
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
