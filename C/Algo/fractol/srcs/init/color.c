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

	rgbtab = NULL;
	if ((rgbtab = malloc(NCOLORS * sizeof(t_rgb))))
	{
		rgbtab[0] = Green;
		rgbtab[1] = Yellow;
		rgbtab[2] = Red;
	}
	return (rgbtab);
}