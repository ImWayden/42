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
	env->t[x + y * SCREEN_H].env = env;
	env->t[x + y * SCREEN_H].x = x;
	env->t[x + y * SCREEN_H].y = y;
	pthread_create(&env->t[x + y * SCREEN_H].t, NULL, env->fract, (void *)&env->t[x + y * SCREEN_H]);
	
	return (0);
}

int			render(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
			{
		ft_putnbr(x);
		ft_putchar(' ');
		ft_putnbr(y);
		ft_putchar('\n');
			threads(env, x, y);
		}
		y++;
	}
	y = 0;
	while (y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			if (pthread_join(env->t[x + y * SCREEN_H].t, NULL))
				printf("join %i %i\n", x, y);	
		}
		y++;
	}
	putpixels(env);
	return(0);
}
