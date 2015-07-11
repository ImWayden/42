/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 22:43:40 by msarr             #+#    #+#             */
/*   Updated: 2015/03/07 22:43:40 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		*rgbmap(void)
{
	t_rgb	*rgbtab;
	int		i;

	rgbtab = NULL;
	i = -1;
	if ((rgbtab = malloc(NCOLORS * sizeof(t_rgb))))
	{
		rgbtab[0] = rgb(66, 30, 15);
    	rgbtab[1] = rgb(25, 7, 26);
    	rgbtab[2] = rgb(9, 1, 47);
    	rgbtab[3] = rgb(4, 4, 73);
    	rgbtab[4] = rgb(0, 7, 100);
	    rgbtab[5] = rgb(12, 44, 138);
	    rgbtab[6] = rgb(24, 82, 177);
    	rgbtab[7] = rgb(57, 125, 209);
    	rgbtab[8] = rgb(134, 181, 229);
    	rgbtab[9] = rgb(211, 236, 248);
    	rgbtab[10] = rgb(241, 233, 191);
    	rgbtab[11] = rgb(248, 201, 95);
    	rgbtab[12] = rgb(255, 170, 0);
    	rgbtab[13] = rgb(204, 128, 0);
    	rgbtab[14] = rgb(153, 87, 0);
    	rgbtab[15] = rgb(106, 52, 3);
		// while (++i < NCOLORS)
		// 	rgbtab[i] = rgb(RANDR (0, 256), RANDR (0, 256)
		// 				, RANDR (0, 256));
	}
	return (rgbtab);
}