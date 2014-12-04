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

void		drawline(t_env env, t_coord p, t_coord p1)
{
  int dx,dy,i,xinc,yinc,cumul,x,y ;
  x = p.x;
  y = p.y;
  dx = p1.x - p.x;
  dy = p1.y - p.y;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx) ;
  dy = abs(dy) ;
  mlx_pixel_put(env.ptr, env.win, x, y, COLOR_WHITE);
  if ( dx > dy ) {
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ ) {
      x += xinc ;
      cumul += dy ;
      if ( cumul >= dx ) {
        cumul -= dx ;
        y += yinc ; }
      mlx_pixel_put(env.ptr, env.win, x, y, COLOR_WHITE); } }
    else {
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) {
      y += yinc ;
      cumul += dx ;
      if ( cumul >= dy ) {
        cumul -= dy ;
        x += xinc ; }
      mlx_pixel_put(env.ptr, env.win, x, y, COLOR_WHITE); } }
 }