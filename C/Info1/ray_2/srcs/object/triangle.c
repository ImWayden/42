/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 14:13:31 by msarr             #+#    #+#             */
/*   Updated: 2014/11/30 14:38:23 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

int			tri_inter(t_ray *ray, t_scene *t, double *distance)
{
    t_vect	pvec;
    t_vect	tvec;
    t_vect	qvec;
    double	det;
    double	u;
    double	v;
    double	d;
    double	inv_det;

    pvec = cross(ray->direc, t->edges[0]);
    det = dot(t->edges[1], pvec);
    if (det < 0.000001)
        return 0;
    tvec = sub(ray->orig, t->a);
    u = dot(tvec, pvec);
    if (u < 0.0 || u > det)
        return 0;
    qvec = cross(tvec, t->edges[1]);
    v = dot(ray->dir, qvec);
    if (v < 0.0 || u + v > det)
        return 0;
    d = dot(t->edges[0], qvec);
    inv_det = 1.0 / det;
    d *= inv_det;
//    u *= inv_det; // may be useful in the future to get texture coordinates
//    v *= inv_det;
    *distance = d;
    return (1);
}