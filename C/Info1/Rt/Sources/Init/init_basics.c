/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:47:46 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 16:47:47 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_coord(t_coord *coord)
{
	coord->x = 0.0;
	coord->y = 0.0;
	coord->z = 0.0;
}

void	init_ppti(t_ppti *ppti)
{
	ppti->bpp = 0;
	ppti->endian = 0;
	ppti->sizeline = 0;
}

void	init_rot(t_rot *rot)
{
	rot->rot_x = 0.0;
	rot->rot_y = 0.0;
	rot->rot_z = 0.0;
}

void	init_color(t_color *color)
{
	color->red = 0;
	color->blue = 0;
	color->green = 0;
	color->new_red = 0;
	color->new_blue = 0;
	color->new_green = 0;
}
