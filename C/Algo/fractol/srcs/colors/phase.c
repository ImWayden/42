/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 09:44:01 by msarr             #+#    #+#             */
/*   Updated: 2015/05/06 09:44:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		phase(double x, double y)
{
	double	angle;

	if (!x)
	{
    	if (y > 0)
    		angle = M_PI / 2;
    	else
    		angle = -M_PI / 2;
    }
    else
    	angle = atan(y / x);
    if (x < 0)
    	angle = angle + M_PI;
    if (angle < 0)
    	angle = angle + 2 * M_PI;
    angle = angle * 3 / M_PI;
    if (angle == 6)
    	angle = 0;
    return (angle);
}
