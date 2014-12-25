/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 15:10:18 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 18:26:37 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect		get_norm(t_scene *scene, t_vect point)
{
	if (scene->type == SPHERE)
		return (divi(sub(point, scene->pos), scene->size));
	if (scene->type == PLAN)
		return (scene->dir);
	return (new(0, 0, 0));
}

int		inter_center(t_ray *ray, t_scene *scene, double *dist)
{
	if (scene->type == SPHERE)
		return (hitSphere(ray, scene, dist));
	if (scene->type == PLAN)
		return (hitplan(ray, scene, dist));
	return (0);
}
