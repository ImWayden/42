/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 15:10:18 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 11:34:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect		get_norm(t_scene *scene, t_vect point)
{
	if (scene->type == SPHERE)
		return (unit(sub(scene->pos, point)));
	return (unit(sub(scene->pos, point)));
}

int		inter_center(t_ray *ray, t_scene *scene, double *dist)
{
	if (scene->type == SPHERE)
		return (sphere_inter(ray, scene, dist));
	return (0);
}
