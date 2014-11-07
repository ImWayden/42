/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/06 22:04:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf.h"

int			forward(t_env *env, double moveSpeed)
{
	int  	i;
	int  	j;

	i = (int)(env->posX + env->dirX * moveSpeed);
	j = (int)env->posY;
	if (!env->worldMap[i][j])
		env->posX += env->dirX * moveSpeed;
	i = (int)(env->posX);
	j = (int)(env->posY + env->dirY * moveSpeed);
	if (!env->worldMap[i][j])
		env->posY += env->dirY * moveSpeed;
	return (1);
}

int			back(t_env *env, double moveSpeed)
{
	int  	i;
	int  	j;

	i = (int)(env->posX - env->dirX * moveSpeed);
	j = (int)env->posY;
	if (!env->worldMap[i][j])
		env->posX -= env->dirX * moveSpeed;
	i = (int)(env->posX);
	j = (int)(env->posY - env->dirY * moveSpeed);
	if (!env->worldMap[i][j])
		env->posY -= env->dirY * moveSpeed;
	return (1);
}

int 			turn_right(t_env *env, double rotSpeed)
{
	double		oldDirX;
	double		oldPlaneX;

	oldDirX = env->dirX;
	env->dirX = env->dirX * cos(-rotSpeed) - env->dirY * sin(-rotSpeed);
	env->dirY = oldDirX * sin(-rotSpeed) + env->dirY * cos(-rotSpeed);
	oldPlaneX = env->planeX;
	env->planeX = env->planeX * cos(-rotSpeed) - env->planeY * sin(-rotSpeed);
	env->planeY = oldPlaneX * sin(-rotSpeed) + env->planeY * cos(-rotSpeed);
	return (1);
}

int 			turn_left(t_env *env, double rotSpeed)
{
	double		oldDirX;
	double		oldPlaneX;

	oldDirX = env->dirX;
	env->dirX = env->dirX * cos(rotSpeed) - env->dirY * sin(rotSpeed);
	env->dirY = oldDirX * sin(rotSpeed) + env->dirY * cos(rotSpeed);
	oldPlaneX = env->planeX;
	env->planeX = env->planeX * cos(rotSpeed) - env->planeY * sin(rotSpeed);
	env->planeY = oldPlaneX * sin(rotSpeed) + env->planeY * cos(rotSpeed);
	return (1);
}		
