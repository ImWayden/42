/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 18:42:03 by msarr             #+#    #+#             */
/*   Updated: 2015/05/27 18:42:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		wall(t_env *env)
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
