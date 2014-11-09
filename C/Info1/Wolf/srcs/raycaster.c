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
	env->rayPosX = env->posX;
	env->rayPosY = env->posY;
	env->rayDirX = env->dirX + env->planeX * env->cameraX;
	env->rayDirY = env->dirY + env->planeY * env->cameraX;
	env->mapX = (int)env->rayPosX;
	env->mapY = (int)env->rayPosY;
	env->deltaDistX = sqrt(1 + (env->rayDirY * env->rayDirY) /
		(env->rayDirX * env->rayDirX));
	env->deltaDistY = sqrt(1 + (env->rayDirX * env->rayDirX) /
		(env->rayDirY * env->rayDirY));
}

void				ray_hit(t_env *env)
{
	int 			hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->sideDistX < env->sideDistY)
		{
			env->sideDistX += env->deltaDistX;
			env->mapX += env->stepX;
			env->side = 0;
		}
		else
		{
			env->sideDistY += env->deltaDistY;
			env->mapY += env->stepY;
			env->side = 1;
		}
		if (env->worldMap[env->mapX][env->mapY] > 0)
			hit = 1;
	}
}

void				ray_draw_coord(t_env *env)
{
	if (env->side == 0)
		env->perpWallDist = fabs((env->mapX - env->rayPosX + (1 - env->stepX) / 2) / env->rayDirX);
	else
		env->perpWallDist = fabs((env->mapY - env->rayPosY + (1 - env->stepY) / 2) / env->rayDirY);
	env->lineHeight = abs((int )(screenHeight/ env->perpWallDist));
	env->drawStart = -env->lineHeight / 2 + screenHeight/ 2;
	if (env->drawStart < 0)
		env->drawStart = 0;
	env->drawEnd = env->lineHeight / 2 + screenHeight/ 2;
	if (env->drawEnd >= screenHeight)
		env->drawEnd = screenHeight- 1;
}

void				ray_dir(t_env *env)
{
	if (env->rayDirX < 0)
	{
		env->stepX = -1;
		env->sideDistX = (env->rayPosX - env->mapX) * env->deltaDistX;
	}
	else
	{
		env->stepX = 1;
		env->sideDistX = (env->mapX + 1.0 - env->rayPosX) * env->deltaDistX;
	}
	if (env->rayDirY < 0)
	{
		env->stepY = -1;
		env->sideDistY = (env->rayPosY - env->mapY) * env->deltaDistY;
	}
	else
	{
		env->stepY = 1;
		env->sideDistY = (env->mapY + 1.0 - env->rayPosY) * env->deltaDistY;
	}
}

int					raycaster(t_env *env)
{
	int x;
	int w;

	w = screenWidth;
	for(x = 0; x < w; x++)
	{
		env->cameraX = 2 * x / (double)(w) - 1;
		ray_init(env);   
		ray_dir(env);	
		ray_hit(env);	
		ray_draw_coord(env);
		draw(env, x);
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img[10]->img, 0, 0);
	return (1);
}