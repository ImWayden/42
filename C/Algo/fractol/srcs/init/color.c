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
		while (++i < NCOLORS)
			rgbtab[i] = rgb(RANDR (0, 256), RANDR (0, 256)
						, RANDR (0, 256));
	}
	return (rgbtab);
}