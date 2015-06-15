/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 13:02:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw(t_env *env, int x)
{
	int		in;
	int		in1;
	int		y;
	int		d;

	wall(env);
	y = env->drawstart;
	env->texnum = env->texnum % 4 ? env->texnum % 4 : env->texnum / 4;
	if (env->side)
		env->texnum += 4;
	while (y < env->drawend)
	{
		d = y * 256 - SCREENHEIGHT * 128 + env->lineheight * 128;
		env->texy = ((d * 64) / env->lineheight) / 256;
		in1 = (env->img[env->texnum]->bpp >> 3)
			* ((env->texy * (env->img[env->texnum]->sizel >> 2)) + env->texx);
		in = (env->img[10]->bpp >> 3)
			* ((y * (env->img[10]->sizel >> 2)) + x);
		env->img[10]->data[in] = env->img[env->texnum]->data[in1];
		env->img[10]->data[in + 1] = env->img[env->texnum]->data[in1 + 1];
		env->img[10]->data[in + 2] = env->img[env->texnum]->data[in1 + 2];
		y++;
	}
	draw_sky(env, x, 0);
	draw_floor(env, x, 1);
}
