/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:20:56 by msarr             #+#    #+#             */
/*   Updated: 2014/10/12 00:52:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ligne(t_env env, float xi,float yi,float xf,float yf)
{
	double x,y ;
	double a,b ;

	if (xi >  xf)
	{
		a = xi;
		b = yi;
		xi = xf;
		yi = yf;
		xf = a;
		yf = b;
	}
	a = (yf-yi)/(xf-xi) ;
	b = yi - a * xi ;
	x = xi;
	while (x <= xf)
	{
		y = (a * x + b) ;
		mlx_pixel_put(env.ptr, env.win, x, y, 0x66CC66);
		x += 0.004;
   }
}

void			fake_expose(t_env env)
{
	int			i;
	int			j;
	t_coord		**tab;

	tab = env.tab;
	i = 0;

	while(tab[i])
	{
		j = 0;
		while (tab[i][j].z != -2)
		{
			if (tab[i][j + 1].z != -2)
				ligne(env,tab[i][j].x, tab[i][j].y,tab[i][j + 1].x, tab[i][j + 1].y);
			if (tab[i + 1])
				ligne(env,tab[i][j].x, tab[i][j].y,tab[i + 1][j].x, tab[i + 1][j].y);
			j++;
		}
		i++;
	}
}
