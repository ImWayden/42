/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trender.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/03 12:55:33 by msarr             #+#    #+#             */
/*   Updated: 2015/07/03 12:55:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*fract(void *arg)
{
	t_env	*env;
	int 	x;
	int 	y;

	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
		env->fract(env, x, y);
	pthread_exit(NULL);
}

void		render(t_env *env)
{
	int		y;
	int		d;

	d = SCREEN_H;
	y = -1;
	pthread_mutex_lock (&env->lock);
	while (++y < d)
	{
		env->t[y].max_i = env->max_i;
		env->t[y].zoom = env->zoom;
		env->t[y].c = cplx(env->c.r, env->c.i);
		if (pthread_create(&env->t[y].t, NULL, fract, (void *)&env->t[y]))
			ft_exit(env, "Thread create error.");
	}
	pthread_mutex_unlock (&env->lock);
	y = -1;
	while (++y < SCREEN_H)
	 	if (pthread_join(env->t[y].t, NULL))
	 		ft_exit(env, "Thread join error.");

	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	putpixels(env);
}
