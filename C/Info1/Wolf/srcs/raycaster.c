/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:20:01 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 02:17:54 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf.h"

void				ray_init(t_env *env)
{
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->deltadistx = sqrt(1 + (env->raydiry * env->raydiry) /
		(env->raydirx * env->raydirx));
	env->deltadisty = sqrt(1 + (env->raydirx * env->raydirx) /
		(env->raydiry * env->raydiry));
}

void				ray_hit(t_env *env)
{
	int				hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (env->worldmap[env->mapx][env->mapy] > 0)
			hit = 1;
	}
}

void				ray_draw_coord(t_env *env)
{
	if (env->side == 0)
		env->perpwalldist = fabs((env->mapx - env->rayposx
			+ (1 - env->stepx) / 2) / env->raydirx);
	else
		env->perpwalldist = fabs((env->mapy - env->rayposy
			+ (1 - env->stepy) / 2) / env->raydiry);
	env->lineheight = abs((int)(SCREENHEIGHT / env->perpwalldist));
	env->drawstart = -env->lineheight / 2 + SCREENHEIGHT / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + SCREENHEIGHT / 2;
	if (env->drawend >= SCREENHEIGHT)
		env->drawend = SCREENHEIGHT - 1;
}

void				ray_dir(t_env *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
	}
}

int					raycaster(t_env *env)
{
	int				x;
	int				w;

	w = SCREENWIDTH;
	x = 0;
	while (x < w)
	{
		env->camerax = 2 * x / (double)(w) - 1;
		ray_init(env);
		ray_dir(env);
		ray_hit(env);
		ray_draw_coord(env);
		draw(env, x);
		x++;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img[10]->img, 0, 0);
	return (1);
}
