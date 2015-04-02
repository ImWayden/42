/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 19:16:35 by msarr             #+#    #+#             */
/*   Updated: 2015/01/28 19:16:35 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coord		coord(double x, double y, double z)
{
	t_coord	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_coord		add(t_coord vect, t_coord vect1)
{
	t_coord	v;

	v.x = vect.x + vect1.x;
	v.y = vect.y + vect1.y;
	v.z = vect.z + vect1.z;
	return (v);
}

t_coord		mult(t_coord vect, double d)
{
	t_coord	v;

	v.x = vect.x * d;
	v.y = vect.y * d;
	v.z = vect.z * d;
	return (v);
}

void		plot3d(t_env *env, t_coord c, t_rgb col)
{
	double	x;
	double	y;

	x = (0.71 * (c.x - c.y) + 10) * 30.0;
	y = (-0.82 * c.z + 0.41 * (c.x + c.y) + 10) * 30.0;
	if (x >= 0 && y >= 0)
	plotpixel(env, (int)x , (int)y, col);
}

void		drawp(t_env *env, t_coord *t)
{
	double	k;
	double	n;
	t_coord	v;
	int		i;
 
	v = coord(0.0,0.0,0.0);
	n = 2;
	env->max_i = 400000;
	while (n < env->max_i)
	{
		k = RANDR(-1, 1);
		i = 0;
		while(i < 3)
 		{
			if (k > ((double)i - 1.0) / 3.0 && k < (double) i / 3.0)
			{
				v = mult(add(v, t[i]), 1.0/2.0);
				plot3d(env, v, White);

			}
			i++;
 		}
		n++;
 	}
}


void		pyramid(t_env *env, t_coord	p, int depth, double z, t_rgb col)
{
	t_coord	t[4];
	t_rgb	r[4];


	int 	i;

	if (depth)
	{
		t[0] = add(p, coord(-z / 2.0, -z / 2.0, -z));
		t[1] = add(p, coord(z / 2.0, -z / 2.0, -z));
		t[2] = add(p, coord(-z / 2.0, z / 2.0, -z));
		t[3] = add(p, coord(z / 2.0, z / 2.0, -z));
		r[0] = Red;
		r[1] = Blue;
		r[2] = Green;
		r[3] = Yellow;
		i = -1;
		while (++i < 4)
		{
			plot3d(env, t[i], r[i]);
			t[i] = mult(add(p, t[i]), 1.0 / 2.0);

		}
		pyramid(env, t[0], depth -1, z / 2.0, r[0]);
		pyramid(env, t[1], depth -1, z / 2.0, r[1]);
		pyramid(env, t[2], depth -1, z / 2.0, r[2]);
		pyramid(env, t[3], depth -1, z / 2.0, r[3]);
		pyramid(env, p, depth -1, z / 2.0, col);
	}
}


int			render_3d(t_env *env)
{
	t_coord	t;
	char str[3];//"༼ つ ◕_◕ ༽つ";

	str[0] = -32;
	str[1] = -68;
	str[2] = -68;
		ft_putendl(str);
	t = coord(0.0, 0.0, 7.0);
	plot3d(env, t, White);
	pyramid(env, t, 8, 7.0, White);
	return (0);
}
