/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 00:18:28 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 02:58:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect			light_dir(t_light *light, t_vect point)
{
	return (unit(sub(point, light->pos)));
}

double			light_diff(t_light *light, t_vect dir, t_vect norm)
{
	double		high;

	high = dot(norm, dir);
	if (high < 0)
		return 0;
	return (high * light->i);
}

double			light_spec(t_light *light, t_vect light_dir, t_vect norm, t_vect ray_dir, double spec)
{
	double		high;
	t_vect		v;
	t_vect		r;
	double		i;
	double		s;


	high = dot(norm, light_dir);
	v = negate(ray_dir);
	r = sub(light_dir, mult2(norm, high * 2.0));
	i = dot(v, r);
	if (i < 0)
		return (0);
	s = pow(i, spec) * KS_CONST * light->i;
	return (s);
}
