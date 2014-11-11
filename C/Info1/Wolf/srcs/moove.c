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

#include "wolf.h"

int				forward(t_env *env, double movespeed)
{
	int			i;
	int			j;

	i = (int)(env->posx + env->dirx * movespeed);
	j = (int)env->posy;
	if (!env->worldmap[i][j])
		env->posx += env->dirx * movespeed;
	i = (int)(env->posx);
	j = (int)(env->posy + env->diry * movespeed);
	if (!env->worldmap[i][j])
		env->posy += env->diry * movespeed;
	return (1);
}

int				back(t_env *env, double movespeed)
{
	int			i;
	int			j;

	i = (int)(env->posx - env->dirx * movespeed);
	j = (int)env->posy;
	if (!env->worldmap[i][j])
		env->posx -= env->dirx * movespeed;
	i = (int)(env->posx);
	j = (int)(env->posy - env->diry * movespeed);
	if (!env->worldmap[i][j])
		env->posy -= env->diry * movespeed;
	return (1);
}

int				turn_right(t_env *env, double rotspeed)
{
	double		olddirx;
	double		oldplanex;

	olddirx = env->dirx;
	env->dirx = env->dirx * cos(-rotspeed) - env->diry * sin(-rotspeed);
	env->diry = olddirx * sin(-rotspeed) + env->diry * cos(-rotspeed);
	oldplanex = env->planex;
	env->planex = env->planex * cos(-rotspeed) - env->planey * sin(-rotspeed);
	env->planey = oldplanex * sin(-rotspeed) + env->planey * cos(-rotspeed);
	return (1);
}

int				turn_left(t_env *env, double rotspeed)
{
	double		olddirx;
	double		oldplanex;

	olddirx = env->dirx;
	env->dirx = env->dirx * cos(rotspeed) - env->diry * sin(rotspeed);
	env->diry = olddirx * sin(rotspeed) + env->diry * cos(rotspeed);
	oldplanex = env->planex;
	env->planex = env->planex * cos(rotspeed) - env->planey * sin(rotspeed);
	env->planey = oldplanex * sin(rotspeed) + env->planey * cos(rotspeed);
	return (1);
}
