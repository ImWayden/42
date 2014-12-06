/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 01:05:34 by msarr             #+#    #+#             */
/*   Updated: 2014/12/06 04:07:04 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lemin.h"

int			pixel_put(t_env *env, int x, int y, int c)
{
	int		in;
	in = (env->bpp >> 3)* ((y * (env->sizel >> 2)) + x);
	env->data[in] = c;
	env->data[in + 1] = c;
	env->data[in + 2] = c;
	return (c);
}

t_room		*drawline(t_env env, t_room p, t_room p1, int z)
{
	int 		dx,dy,i,xinc,yinc,cumul,x,y ;
	x = p.x;
	y = p.y;
	dx = p1.x - p.x;
	dy = p1.y - p.y;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	t_room	*r;

	r = NULL;
	pixel_put(&env, x, y, 255);
	if ( dx > dy )
	{
		cumul = dx / 2 ;
		for (i = 1 ; i <= dx ; i++)
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
				pixel_put(&env, x, y, 255);
				r = new_room(p.name, x, y);
			}
		}
	}
	else
	{
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ )
		{
			y += yinc ;
			cumul += dx ;
			if ( cumul >= dy )
			{
				cumul -= dy ;
				x += xinc ;
			}
			if (sqrt(SQUARE(p.x - x) + SQUARE(p.y - y)) <= z)
			{
				pixel_put(&env, x, y, 255);
				r = new_room(p.name, x, y);
			}
		}
	}
	return (r);
 }