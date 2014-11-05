/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:20:01 by msarr             #+#    #+#             */
/*   Updated: 2014/11/04 12:20:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf.h"

int					raycaster(t_env *env)
{
	double cameraX;    
	double rayPosX;
	double rayPosY;
	double rayDirX;
	double rayDirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit = 0;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int texNum;
	int mapX;
	int mapY;
	int x;
	int y;
	int w;
	int h;
	int color;

	
	w = screenWidth;
	h = screenHeight;
	for(x = 0; x < w; x++)
	{
		cameraX = 2 * x / (double)(w) - 1;    
		rayPosX = env->posX;
		rayPosY = env->posY;
		rayDirX = env->dirX + env->planeX * cameraX;
		rayDirY = env->dirY + env->planeY * cameraX;
		mapX = (int)rayPosX;
		mapY = (int)rayPosY;
		deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (env->worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = fabs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
		else
			perpWallDist = fabs((mapY - rayPosY + (1 - stepY) / 2) / rayDirY);
		lineHeight = abs((int )(h / perpWallDist));
		drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		if ((texNum = env->worldMap[mapX][mapY]) >= 0)
		{
			color = env->texture[texNum];
			if (side == 1)
				color = color >> 1;
			int in;
			for (y = 0; y < h; y++)
			{
				
				if (y >= drawStart && y < drawEnd)
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
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (1);
}