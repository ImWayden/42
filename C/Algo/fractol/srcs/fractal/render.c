/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 21:49:32 by msarr             #+#    #+#             */
/*   Updated: 2015/01/25 21:49:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int     		threads(t_env *env, int x, int y)
{
	static	int	z = -1;
	int			d;

	d = y;// x + y * SCREEN_W;
	env->t[d].env = env;
	env->t[d].y = y;
	env->t[d].x = x;
	if (pthread_create(&env->t[d].t, NULL, env->fract, (void *)&env->t[d]) || d == SCREEN_H - 1)
	{
		while (++z < SCREEN_H)
			if (pthread_join(env->t[z].t, NULL))
				exit (0);
	}
	else
		return (++x);
	return (x);
}

int			render(t_env *env)
{
	int		y;
	int		x;

	y = -1;
	while (++y < SCREEN_H && (x = -1))
		//while (x < SCREEN_W)
			x = threads(env, x, y);
	putpixels(env);
	return(0);
}
