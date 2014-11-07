/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/06 21:41:07 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf.h"

void			draw(t_env *env, int x)
{
	int			in;
	int			color;
	int			y;

	if ((env->texNum = env->worldMap[env->mapX][env->mapY]) >= 0)
	{
		color = env->texture[env->texNum];
		if (env->side == 1)
			color = color >> 1;
		for (y = 0; y < screenHeight; y++)
		{	
			if (y >= env->drawStart && y < env->drawEnd)
			{
				in = (env->bpp >> 3) * ((y * (env->sizel >> 2)) + x);
				env->data[in] = color & 0xff;
				env->data[in + 1] = (color & 0xff00) >> 8;
				env->data[in + 2] = (color & 0xff0000) >> 16;
			}
			else
			{
				in = (env->bpp >> 3) * ((y * (env->sizel >> 2)) + x);
				env->data[in] = WHITE_2 & 0xff;
				env->data[in + 1] = (WHITE_2 & 0xff00) >> 8;
				env->data[in + 2] = (WHITE_2 & 0xff0000) >> 16;
			}
		}
	}
}