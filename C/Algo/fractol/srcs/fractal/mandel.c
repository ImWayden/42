/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:03:34 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 15:03:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		getarg(void *arg, t_env **env, int *x, int *y)
{
	*env = ((t_thread *)arg)->env;
	*x = ((t_thread *)arg)->x;
	*y = ((t_thread *)arg)->y;
}

void		*mandel(void *arg)
{
	t_env	*env;
	int		x;
	int		y;
	int		i;
	t_cplx	 z;
	t_cplx	 a;
	t_cplx	 c;

	i = 0;
	getarg(arg, &env, &x, &y);
	c.r = (double)x / env->zoom_x + env->x_min;
	c.i = env->y_max - (double)y / env->zoom_y;
	z = cplx(0.0, 0.0);
	a = cplx(c.r, c.i);
	while (mod(z) < 4 && i < env->max_i)
	{
		pthread_mutex_lock(&env->mutex); /* On verrouille le mutex */
		z = cplx_add(cplx_mult(z, z), c);
		a = curl(env->coeff[i % env->nc], a.r, a.i);
		pthread_mutex_unlock(&env->mutex); 
		i++;
	}
	pthread_mutex_lock(&env->mutex); /* On verrouille le mutex */
	if (i == env->max_i)
		plotpixel(env, x, y, Black);
	else
		plotpixel(env, x, y, getcolor(a));
	pthread_mutex_unlock(&env->mutex); 
	pthread_exit(NULL);
	return (NULL);
}
