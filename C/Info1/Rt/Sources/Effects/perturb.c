/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:00:35 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 17:00:50 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void	ptb_norm(double *nx, double *ny, double *nz, t_objet obj3)
{
	*ny = *ny + (cos(obj3.coord.y / 2) * (sqrt(SQ(*nx) +
					SQ(*ny) + SQ(*nz)) / 2));
}
