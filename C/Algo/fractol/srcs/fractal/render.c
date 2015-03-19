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


int     		threads(t_env *env, int y)
{
	env->t[y].env = env;
	env->t[y].y = y;
	pthread_create(&env->t[y].t, NULL, env->fract, (void *)&env->t[y]);
	return (0);
}

int			render(t_env *env)
{
	int		y;

	y = -1;
	while (++y < SCREEN_H)
		threads(env, y);
	y = -1;
	while (++y < SCREEN_H)
		if (pthread_join(env->t[y].t, NULL))
			exit (0);
	putpixels(env);
	return(0);
}
