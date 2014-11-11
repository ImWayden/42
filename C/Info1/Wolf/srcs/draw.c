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

int				wall_calcul(t_env *env)
{
	env->texnum = env->worldmap[env->mapx][env->mapy];
	if (env->side == 1)
		env->wallx = env->rayposx + ((env->mapy - env->rayposy
			+ (1 - env->stepy) / 2) / env->raydiry) * env->raydirx;
	else
		env->wallx = env->rayposy + ((env->mapx - env->rayposx
			+ (1 - env->stepx) / 2) / env->raydirx) * env->raydiry;
	env->wallx -= floor((env->wallx));
	env->texx = (int)(env->wallx * 64);
	if (env->side == 0 && env->raydirx > 0)
		env->texx = 64 - env->texx - 1;
	if (env->side == 1 && env->raydiry < 0)
		env->texx = 64 - env->texx - 1;
	return (1);
}

int				drawing_wall(t_env *env, int x)
{
	int			in;
	int			in1;
	int			y;
	int			d;

	wall_calcul(env);
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
	return (1);
}

void			draw(t_env *env, int x)
{
	drawing_floor(env, x, 1);
	drawing_wall(env, x);
	drawing_sky(env, x, 0);
}
