/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 01:05:34 by msarr             #+#    #+#             */
/*   Updated: 2014/12/03 02:33:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "lemin.h"

void		drawline(t_env env, t_room p, t_room p1, int z)
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

	mlx_pixel_put(env.ptr, env.win, x, y, COLOR_WHITE);
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
				mlx_pixel_put(env.ptr, env.win, x, y, COLOR_WHITE);
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
				mlx_pixel_put(env.ptr, env.win, x, y, COLOR_WHITE);
				r = new_room(p.name, x, y);
			}
		}
	}
	draw_s(&env, *r, 5);
	sleep(1);
	draw_s(&env, *r, 5);
 }