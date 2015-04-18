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

void		*render(void *envp)
{
	int		y;
	int		d;
	t_env	*env;

	d = SCREEN_H;
	y = -1;
	env = (t_env *)envp;
	pthread_mutex_lock (&env->lock);
	while (++y < d)
	{
		env->t[y].max_i = env->max_i;
		env->t[y].zoom = env->zoom;
		env->t[y].c = cplx(env->c.r, env->c.i);
		if (pthread_create(&env->t[y].t, NULL, env->fract, (void *)&env->t[y]))
			ft_exit(env, "Thread create error.");
	}
	pthread_mutex_unlock (&env->lock);
	y = -1;
	while (++y < SCREEN_H)
	 	if (pthread_join(env->t[y].t, NULL))
	 		ft_exit(env, "Thread join error.");
	 ft_putendl("render");
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	// //putpixels(env);
	return(0);
}
