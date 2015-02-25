/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:16:19 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 22:16:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *env)
{
	env->ranx = SCREEN_W / env->zoom_x;
	env->rany = SCREEN_H / env->zoom_y;
	env->y_min = env->pty - env->rany / 2.0;
	env->y_max = env->pty + env->rany / 2.0;
	env->x_min = env->ptx - env->ranx / 2.0;
	env->x_max = env->ptx + env->ranx / 2.0;
}

int		mouse_press(int button, int x, int y, t_env *env)
{
	if (button == 5  || button == 4)
	{
		gettimeofday(&(env->end), NULL);
		if ((env->end.tv_sec - env->start.tv_sec) > 1)
		{
			env->ptx = (double)x / env->zoom_x + env->x_min;
			env->pty = env->y_max - (double)y / env->zoom_y;
		}
		if (button == 4)
		{
			env->zoom_x *= 1 - env->zoom_factor * 2.0;
			env->zoom_y *= 1 - env->zoom_factor * 2.0;
		}
		if (button == 5)
		{
			env->zoom_x *= 1 + env->zoom_factor * 2.0;
			env->zoom_y *= 1 + env->zoom_factor * 2.0;
		}
		gettimeofday(&(env->start), NULL);
	}
	return 0;
}

int		mouse_motion(int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (env->conf)
		env->conf = (env->conf % 46) + 1;
	return (0);
}

int		loop_hook(t_env *env)
{
	int		i;

	zoom(env);
	i = 0;
	while (i < 100)
	{
		if (0 != pthread_create(&env->threadtab[i].thread, NULL, env->funct, (void *)&env->threadtab[i]))
			exit (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < 100)
	{
		if (pthread_join(env->threadtab[i].thread, NULL))
			exit (1);
		i++;
	}
	expose(env);
	sleep(50);
	return (0);
}
