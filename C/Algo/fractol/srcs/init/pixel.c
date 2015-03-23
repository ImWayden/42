/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 01:49:02 by msarr             #+#    #+#             */
/*   Updated: 2015/03/23 01:49:02 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb			*pixelmap(void)
{
	int		x;
	int		d;
	t_rgb	*pixels;

	x = -1;
	d = SCREEN_H * SCREEN_W;
	pixels = NULL;
	if ((pixels = malloc(sizeof(t_rgb) * d)))
		while (++x < d)
			pixels[x] = rgb(0, 0, 0);
	return (pixels);
}
