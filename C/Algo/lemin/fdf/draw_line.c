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

static void	draw(int dx, int dy)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = dx / 2 ;
	while (i <= dx)
	{
		x += xinc ;
		cumul += dy ;
		if ( cumul >= dx )
		{
			cumul -= dx ;
			y += yinc ;
		}
		if (sqrt(SQUARE(p.x - x) + SQUARE(p.y - y)) <= z)
		{
			pixel_put(&env, x, y, c);
			r = new_room(p.name, x, y);
		}
		i++;
	}
}

t_room		*drawline(t_env env, t_room p, t_room p1, int z)
{
	int 		dx;
	int			dy;
	int			i;
	int			xinc;
	int			yinc;
	int			x;
	int			y;
	t_room		*r;
	int			c;

	x = p.x;
	y = p.y;
	dx = p1.x - p.x;
	dy = p1.y - p.y;
	xinc = (dx > 0 ) ? 1 : -1 ;
	yinc = (dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	if (p.dist > 1000 || p1.dist > 1000)
		c = COLOR_RED;
	r = NULL;
	pixel_put(&env, x, y, c);
	if (dx > dy)
		draw(dx, dy, xinc, yinc)
	else
		draw(dy, dx, yinc, xinc)
	return (r);
 }