/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 15:55:55 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 02:27:47 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_ray		ray_addnoise(t_ray *ray, double epsilon)
{
	double	r;
	t_ray	new;

	r = (((double)rand()/RAND_MAX) * 2 * epsilon) - epsilon;
	new = *ray;
	new.dir.x += r;
	r = (((double)rand()/RAND_MAX) * 2 * epsilon) - epsilon;
	new.dir.y += r;
	r = (((double)rand()/RAND_MAX) * 2 * epsilon) - epsilon;
	new.dir.z += r;
	new.dir = unit(ray->dir);
	return (new);
}