/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:16:31 by msarr             #+#    #+#             */
/*   Updated: 2015/04/20 22:16:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static t_cplx		midpoint(t_cplx	p1, t_cplx p2)
{  
   return (cplx((p1.r + p2.r) / 3.0, (p1.i + p2.i) / 3.0));
}

void		sierpinski(t_env *env)
{
	int		i;
	int		x;
	int		y;
	//t_cplx	randcorner;
	t_cplx	corners[4];
	t_cplx	bluecorner = cplx(0.0, sqrt(3) / 2.0);
	t_cplx	corner = cplx(0.0, -sqrt(3) / 2.0);
	t_cplx	redcorner = cplx(-1.0 / 2.0, 0.0);
	t_cplx	greencorner = cplx(1.0 / 2.0, 0.0);
	t_cplx	randcorner = cplx(env->ptx, env->pty);
	t_cplx	pivot = bluecorner;

	i = 1;
	corners[0] = redcorner;
	corners[1] = bluecorner;
	corners[2] = greencorner;
	corners[3] = corner;
	ft_bzero(env->data, 600 * 600 * 4);
	while (i < 50000)
	{  
   		randcorner = corners[rand() % 4];
   		pivot = midpoint(pivot, randcorner);
   		x = ((pivot.r - env->ptx) * env->zoom) + (SCREEN_W / 2);
		y = ((pivot.i - env->pty) * env->zoom) + (SCREEN_H / 2);
		if (x < 600 && y < 600 && x > 0 && y > 0)
		{
	   		plotpixel(env, x, y, rgb(255, 0, 0));
	   		i++;
	   	}
   	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}
