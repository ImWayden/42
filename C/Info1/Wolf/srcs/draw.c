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

#include "Wolf.h"

int			drawing(t_env *env, int x, int y, t_img *img, int m)
{
	int			in;
	int			in1;
	int			x2;
	int			y2;
	int			a;

	if (m == env->drawEnd )
 		a = screenWidth / (env->drawEnd - env->drawStart);
	else if (m == env->drawStart)
 		a = screenHeight / (0 - env->drawStart);
 	else
 		a = screenHeight / (screenHeight - env->drawEnd);
	x2 = x % 64;
	y2 = y % 64;
	in1 = (img->bpp >> 3) * ((y2 * (img->sizel >> 2)) + x2);
	while (a-- && y < m)
	{
		in = (env->img[10]->bpp >> 3) * ((y * (env->img[10]->sizel >> 2)) + x);
		env->img[10]->data[in] = img->data[in1];
		env->img[10]->data[in + 1] = img->data[in1 + 1];
		env->img[10]->data[in + 2] = img->data[in1 + 2];
		y++;
	}
	return (y);
}

void			draw(t_env *env, int x)
{
	int			y;
	//t_img		*img;
	t_img		*img2;

	//img = env->img[10];
	if ((env->texNum = env->worldMap[env->mapX][env->mapY]) >= 0)
	{
		//if (env->texNum > 3)
		//	env->texNum -= 4;
		if (env->side == 1)
			img2 = env->img[2];
		else
			img2 = env->img[1];
		y = 0;
		while (y < screenHeight)
		{
				
			if (y >= env->drawStart && y < env->drawEnd)
				y = drawing(env, x, y, img2, env->drawEnd);
			else if (y < env->drawStart)
				y = drawing(env, x, y, env->img[0], env->drawStart);
			else
				y = drawing(env, x, y, env->img[0], screenHeight);
		}
	}
}