/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:49:45 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 17:45:20 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<math.h>
#include	"rt.h"

double		check_whatlim(double k, t_utils *utils)
{
	double	x;
	double	y;

	x = k * utils->vect.v_x + utils->coord.x;
	y = k * utils->vect.v_y + utils->coord.y;
	if ((pow(x, 2) + pow(y, 2)) < pow(700, 2))
		return (k);
	else
		return (-1);
}

double		inter_plan(t_utils utils, t_objet *obj)
{
	double	k;

	obj = obj;
	if (utils.vect.v_z == 0.0000)
		k = -1.0;
	else
		k = -(utils.coord.z / utils.vect.v_z);
	return (k);
}
