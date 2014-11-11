/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:39:18 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 22:39:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			floor_calcul(t_env *env)
{
	if (env->side == 0 && env->raydirx > 0)
	{
		env->floorxwall = env->mapx;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 0 && env->raydirx < 0)
	{
		env->floorxwall = env->mapx + 1.0;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 1 && env->raydiry > 0)
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy;
	}
	else
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy + 1.0;
	}
	env->distwall = env->perpwalldist;
	env->distplayer = 0.0;
	if (env->drawend < 0)
		env->drawend = SCREENHEIGHT;
}

void			drawing_floor(t_env *env, int x, int z)
{
	int			in;
	int			in1;
	int			y;

	floor_calcul(env);
	y = env->drawend;
	while (++y < SCREENHEIGHT)
	{
		env->currentdist = SCREENHEIGHT / (2.0 * y - SCREENHEIGHT);
		env->weight = (env->currentdist - env->distplayer)
			/ (env->distwall - env->distplayer);
		env->currentfloorx = env->weight * env->floorxwall
			+ (1.0 - env->weight) * env->posx;
		env->currentfloory = env->weight * env->floorywall
			+ (1.0 - env->weight) * env->posy;
		env->floortexx = (int)(env->currentfloorx * 64) % 64;
		env->floortexy = (int)(env->currentfloory * 64) % 64;
		in1 = (env->img[z]->bpp >> 3)
			* ((env->floortexy * (env->img[z]->sizel >> 2)) + env->floortexx);
		in = (env->img[10]->bpp >> 3)
			* ((y * (env->img[10]->sizel >> 2)) + x);
		env->img[10]->data[in] = env->img[z]->data[in1];
		env->img[10]->data[in + 1] = env->img[z]->data[in1 + 1];
		env->img[10]->data[in + 2] = env->img[z]->data[in1 + 2];
	}
}
