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
/*iterations=40000*/
t_coord		newc(double x, double y, double z)
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

t_point		*addlist(t_point *p, t_coord c)
{
	t_point	*tmp;

	tmp = malloc(sizeof(t_point));
	tmp->c.x =  0.71 * (c.x - c.y) * SCREEN_W;
	tmp->c.y = (-0.82 * c.z + 0.41 * (c.x + c.y)) * SCREEN_H;
	tmp->next = p;
	return (tmp);
}

int			pyramid(t_env *env)
{
	t_coord	t[6];
	t_coord	v;
	t_point	*list = NULL;
	int		i;
	int		n;
	double	k;

	t[1] = newc(0.0, 0.0, 0.0);
	t[2] = newc(0.0, 1.0/2.0, 0.0);
	t[3] = newc(1.0/2.0, 0.0, 0.0);
	t[4] = newc(1.0/2.0, 1.0/2.0, 0.0);
	t[5] = newc(1.0/4.0, 1.0/4.0, 1.0/2.0);
	printf("%lf\n", t[5].x);
	v = newc(0.0,0.0,0.0);
	n = 2;
			int j = 0;
	env->max_i = 40000;
	while (n < env->max_i)
	{
		k = RANDR(0, 1);
		i = 1;
		while(i < 5)
		{
			if (k > ((double)i-1.0)/5.0 && k < (double)i/5.0)
			{
				v = add(mult(v, 1.0/2.0), t[i]);
				list = addlist(list, v);
				printf("hhh %lf - %lf\n", list->c.x, list->c.y);
				j++;
			}
			i++;
		}
		n++;
	}
	while (list)
	{
		plotpixel(env, (int)list->c.x , (int)list->c.y, LightGrey);
		list = list->next;
	}
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	ft_putendl("ok");
	return (0);
}