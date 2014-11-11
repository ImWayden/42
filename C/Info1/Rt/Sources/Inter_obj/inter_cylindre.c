/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:48:54 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 17:36:56 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	"rt.h"

double		inter_cylindre(t_utils utils, t_objet *obj)
{
	double	a;
	double	b;
	double	c;
	double	r;
	double	d;

	r = obj->size;
	a = pow(utils.vect.v_x, 2) \
		+ pow(utils.vect.v_y, 2);
	b = ((2 * utils.vect.v_x * utils.coord.x) \
		+ (2 * utils.vect.v_y * utils.coord.y));
	c = pow(utils.coord.x, 2) \
		+ pow(utils.coord.y, 2) \
		- pow(r, 2);
	d = delta(a, b, c);
	return (search_res(a, b, d));
}
