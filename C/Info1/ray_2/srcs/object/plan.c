/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 14:13:31 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 18:27:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

int		hitplan(t_ray *ray, t_scene *scene, double *dist)
{
    double t;
    double dv;

    dv = dot(ray->dir, scene->dir);
    if (dv == 0)
        return (0);
    t = -dot(scene->dir, sub(ray->orig, scene->pos)) / dv ;
    if (t < EPSILON)
        return (0);
    *dist = t;                 
    return (1);; 
}