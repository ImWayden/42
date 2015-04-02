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

int			render(t_env *env)
{
	int		y;
	int		d;

	d = SCREEN_H;
	y = -1;
	while (++y < d)
		if (pthread_create(&env->t[y].t, NULL, env->fract, (void *)&env->t[y]))
			ft_exit(env, "Thread create error.");
	y = -1;
	while (++y < SCREEN_H)
	 	if (pthread_join(env->t[y].t, NULL))
	 		ft_exit(env, "Thread join error.");
	// //putpixels(env);
	return(0);
}
