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

void            drawing_sky(t_env *env, int x, int z)
{
	int 		in;
	int 		in1;
	double      floorXWall;
	double      floorYWall;
	double		distWall;
	double		distPlayer;
	double		currentDist;
	double 		weight;
	double 		currentFloorX;
	double 		currentFloorY;
	int 			floorTexX;
	int 			floorTexY;
	int 			y;
	if(env->side == 0 && env->rayDirX > 0)
	{
		floorXWall = env->mapX;
		floorYWall = env->mapY + env->wallX;
	}
	else if(env->side == 0 && env->rayDirX < 0)
	{
		floorXWall = env->mapX + 1.0;
		floorYWall = env->mapY + env->wallX;
	  }
	  else if(env->side == 1 && env->rayDirY > 0)
	{
		floorXWall = env->mapX + env->wallX;
		floorYWall = env->mapY;
	}
	else
	{
		floorXWall = env->mapX + env->wallX;
		floorYWall = env->mapY + 1.0;
	} 
	distWall = env->perpWallDist;
	distPlayer = 0.0;
	if (env->drawStart < 0)
		env->drawStart = 0;
	for(y = 0; y < env->drawStart; y++)
	{
		currentDist = screenHeight / (2.0 * y - screenHeight);
		weight = (currentDist - distPlayer) / (distWall - distPlayer);
		currentFloorX = weight * floorXWall + (1.0 - weight) * env->posX;
		currentFloorY = weight * floorYWall + (1.0 - weight) * env->posY;
		floorTexX = (int)(currentFloorX * 64) % 64;
		floorTexY = (int)(currentFloorY * 64) % 64;
		in1 = (env->img[z]->bpp >> 3)
			* ((floorTexY * (env->img[z]->sizel >> 2)) + floorTexX);
		in = (env->img[10]->bpp >> 3)
			* ((y * (env->img[10]->sizel >> 2)) + x);
		env->img[10]->data[in] = env->img[env->texNum]->data[in1];
		env->img[10]->data[in + 1] = env->img[z]->data[in1 + 1];
		env->img[10]->data[in + 2] = env->img[z]->data[in1 + 2];
	}
}

void            drawing_floor(t_env *env, int x, int z)
{
	int 		in;
	int 		in1;
	double      floorXWall;
	double      floorYWall;
	double		distWall;
	double		distPlayer;
	double		currentDist;
	double 		weight;
	double 		currentFloorX;
	double 		currentFloorY;
	int 			floorTexX;
	int 			floorTexY;
	int 			y;
	if(env->side == 0 && env->rayDirX > 0)
	{
		floorXWall = env->mapX;
		floorYWall = env->mapY + env->wallX;
	}
	else if(env->side == 0 && env->rayDirX < 0)
	{
		floorXWall = env->mapX + 1.0;
		floorYWall = env->mapY + env->wallX;
	  }
	  else if(env->side == 1 && env->rayDirY > 0)
	{
		floorXWall = env->mapX + env->wallX;
		floorYWall = env->mapY;
	}
	else
	{
		floorXWall = env->mapX + env->wallX;
		floorYWall = env->mapY + 1.0;
	} 
	distWall = env->perpWallDist;
	distPlayer = 0.0;
	if (env->drawEnd < 0)
		env->drawEnd = screenHeight;
	for(y = env->drawEnd + 1; y < screenHeight; y++)
	{
		currentDist = screenHeight / (2.0 * y - screenHeight);
		weight = (currentDist - distPlayer) / (distWall - distPlayer);
		currentFloorX = weight * floorXWall + (1.0 - weight) * env->posX;
		currentFloorY = weight * floorYWall + (1.0 - weight) * env->posY;
		floorTexX = (int)(currentFloorX * 64) % 64;
		floorTexY = (int)(currentFloorY * 64) % 64;
		in1 = (env->img[z]->bpp >> 3)
			* ((floorTexY * (env->img[z]->sizel >> 2)) + floorTexX);
		in = (env->img[10]->bpp >> 3)
			* ((y * (env->img[10]->sizel >> 2)) + x);
		env->img[10]->data[in] = env->img[env->texNum]->data[in1];
		env->img[10]->data[in + 1] = env->img[z]->data[in1 + 1];
		env->img[10]->data[in + 2] = env->img[z]->data[in1 + 2];
	}
}

int				wall_calcul(t_env *env)
{
	env->texNum = env->worldMap[env->mapX][env->mapY];
	if (env->side == 1)
		env->wallX = env->rayPosX + ((env->mapY - env->rayPosY + (1 - env->stepY)
			/ 2) / env->rayDirY) * env->rayDirX;
	else
		env->wallX = env->rayPosY + ((env->mapX - env->rayPosX + (1 - env->stepX)
			/ 2) / env->rayDirX) * env->rayDirY;
	env->wallX -= floor((env->wallX));
	env->texX = (int)(env->wallX * 64);
	if (env->side == 0 && env->rayDirX > 0)
		env->texX = 64 - env->texX - 1;
	if (env->side == 1 && env->rayDirY < 0)
		env->texX = 64 - env->texX - 1;
	return (1);
}

int             drawing_wall(t_env *env, int x)
{
	int         in;
	int         in1;
	int         y;
	int         d;
	
	wall_calcul(env);
	for (y = env->drawStart; y < env->drawEnd; y++)
	{
		d = y * 256 - screenHeight * 128 + env->lineHeight * 128;
		env->texY = ((d * 64) / env->lineHeight) / 256;
		in1 = (env->img[env->texNum]->bpp >> 3)
			* ((env->texY * (env->img[env->texNum]->sizel >> 2)) + env->texX);
		in = (env->img[10]->bpp >> 3)
			* ((y * (env->img[10]->sizel >> 2)) + x);
		env->img[10]->data[in] = env->img[env->texNum]->data[in1];
		env->img[10]->data[in + 1] = env->img[env->texNum]->data[in1 + 1];
		env->img[10]->data[in + 2] = env->img[env->texNum]->data[in1 + 2];
	}
	return (1);
}

void            draw(t_env *env, int x)
{
	drawing_floor(env, x, 9);
	drawing_sky(env, x, 0);
	drawing_wall(env, x);
}