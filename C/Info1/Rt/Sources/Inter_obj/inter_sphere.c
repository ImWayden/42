/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:49:54 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 17:46:07 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"rt.h"

double	inter_sphere(t_utils utils, t_objet *obj)
{
	double	a;
	double	b;
	double	c;
	double	r;
	double	d;

	r = obj->size;
	a = pow(utils.vect.v_x, 2.00) \
		+ pow(utils.vect.v_y, 2.00) \
		+ pow(utils.vect.v_z, 2.00);
	b = (2.0 * utils.vect.v_x * utils.coord.x) \
		+ (2.0 * utils.vect.v_y * utils.coord.y) \
		+ (2.0 * utils.vect.v_z * utils.coord.z);
	c = (pow(utils.coord.x, 2.00) \
		+ pow(utils.coord.y, 2.00) \
		+ pow(utils.coord.z, 2.00)) \
		- (pow(r, 2.00));
	d = delta(a, b, c);
	return (search_res(a, b, d));
}
