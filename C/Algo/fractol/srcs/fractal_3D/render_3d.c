












				c.i = (v.y * env->zoom) + (SCREEN_H / 2);
				c.r = (v.x * env->zoom) + (SCREEN_W / 2);
				plotpixel(env, (int)c.r, (int)c.i, Red);
				v = mult(add(v, t[i]), 1.0 / 2.0);
			i++;
			if (k > ((double)i - 1.0) / 4.0 && k < (double) i / 2.0)
			{
			}
		i = 0;
		k = RANDR(-2, 1);
		n++;
		while(i < 3)
	double	k;
	double	n;
	double	x;
	double	y;
	drawp(env, t);
	env->max_i = 500000;
	if (x >= 0 && y >= 0)
	int		i;
	n = 2;
	plotpixel(env, (int)x , (int)y, col);
	return (0);
	return (v);
	return (v);
	return (v);
	t[0] = coord(-1.0, 1.0, 0.0);
	t[1] = coord(-1.0, -1.0, 0.0);
	t[2] = coord(0.0, 0.0, 0.0);
	t_coord	t[5];
	t_coord	v;
	t_coord	v;
	t_coord	v;
	t_coord	v;
	t_cplx	c;
	v = coord(0.0,0.0,0.0);
	v.x = vect.x * d;
	v.x = vect.x + vect1.x;
	v.x = x;
	v.y = vect.y * d;
	v.y = vect.y + vect1.y;
	v.y = y;
	v.z = vect.z * d;
	v.z = vect.z + vect1.z;
	v.z = z;
	while (n < env->max_i)
	x = (0.71 * (c.x - c.y) + 10) * 30.0;
	y = (-0.82 * c.z + 0.41 * (c.x + c.y) + 10) * 30.0;
	{
 
 		{
 		}
 	}
#include "fractol.h"
--/+     	Œ&œ&		&(--)
/*                                                                            */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                    +:+ +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*   Created: 2015/01/28 19:16:35 by msarr             #+#    #+#             */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*   Updated: 2015/01/28 19:16:35 by msarr            ###   ########.fr       */
/* ************************************************************************** */
/* ************************************************************************** */
int			render_3d(t_env *env)
t_coord		add(t_coord vect, t_coord vect1)
t_coord		coord(double x, double y, double z)
t_coord		mult(t_coord vect, double d)
void		drawp(t_env *env, t_coord *t)
void		plot3d(t_env *env, t_coord c, t_rgb col)
{
{
{
{
{
{
}
}
}
}
}"Œ	"