/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:48:45 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 17:39:27 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rt.h"

double		inter_cone(t_utils utils, t_objet *obj)
{
	double	a;
	double	b;
	double	c;
	double	r;
	double	d;

	r = obj->size * M_PI / 100;
	a = pow(utils.vect.v_x, 2) \
		+ pow(utils.vect.v_y, 2) \
		- (pow(utils.vect.v_z, 2) \
		* (pow(tan(r), 2)));
	b = (2 * utils.vect.v_x * utils.coord.x) \
		+ (2 * utils.vect.v_y * utils.coord.y) \
		- ((2 * utils.vect.v_z * utils.coord.z) \
		* (pow(tan(r), 2)));
	c = (pow(utils.coord.x, 2) \
		+ pow(utils.coord.y, 2) \
		- (pow(utils.coord.z, 2) \
		* pow(tan(r), 2)));
	d = delta(a, b, c);
	return (search_res(a, b, d));
}
