/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 01:05:34 by msarr             #+#    #+#             */
/*   Updated: 2014/12/10 07:17:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lemin.h"

int			pixel_put(t_env *env, int x, int y, int c)
{
	int		in;

	in = (env->bpp >> 3)* ((y * (env->sizel >> 2)) + x);
	env->data[in] = c & 0xff;
	env->data[in + 1] = (c & 0xff00) >> 8;;
	env->data[in + 2] = (c & 0xff0000) >> 16;
	return (c);
}
 
t_room		*drawline(t_env env, t_room p, t_room p1, int z)
{
	int		x;
	int		y;
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
	t_room *r = NULL;

	dx = abs(p1.x-p.x);
	sx = p.x<p1.x ? 1 : -1;
	dy = abs(p1.y-p.y);
	sy = p.y<p1.y ? 1 : -1;
	err = (dx >dy ? dx : -dy) / 2;
	x = p.x;
	y = p.y;
	while (42)
	{
		if (sqrt(SQUARE(x - p.x) + SQUARE(y - p.y)) <= z)
		{
			pixel_put(&env, p.x, p.y, color(p.z));
			r = new_room(p.name, p.x, p.y);
		}
		if (p.x==p1.x && p.y==p1.y)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			p.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			p.y += sy;
		}
	}
	return (r);
}
