/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:52:29 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/14 21:35:15 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "wolf3d.h"

void	draw(t_env *e)
{
	int			i;

	i = 0;

	while (i < SCREEN_X)
	{
		e->cameraX = 2 * i / (double)SCREEN_X - 1;
		e->rayPosX = e->posX;
		e->rayPosY = e->posY;
		e->rayDirX = e->dirX + e->planeX * e->cameraX;
		e->rayDirY = e->dirY + e->planeY * e->cameraX;
		e->mapX = (int)e->rayPosX;
		e->mapY = (int)e->rayPosY;
		e->deltaDistX = sqrt(1 + (e->rayDirY * e->rayDirY) / (e->rayDirX * e->rayDirX));
		e->deltaDistY = sqrt(1 + (e->rayDirX * e->rayDirX) / (e->rayDirY * e->rayDirY));
		e->hit = 0;

		if (e->rayDirX < 0)
		{
			e->stepX = -1;
			e->sideDistX = (e->rayPosX - e->mapX) * e->deltaDistX;
		}
		else
		{
			e->stepX = 1;
			e->sideDistX = (e->mapX + 1.0 - e->rayPosX) * e->deltaDistX;
		}
		if (e->rayDirY < 0)
		{
			e->stepY = -1;
			e->sideDistY = (e->rayPosY - e->mapY) * e->deltaDistY;
		}
		else
		{
			e->stepY = 1;
			e->sideDistY = (e->mapY + 1.0 - e->rayPosY) * e->deltaDistY;
		}

		while (e->hit == 0)
		{
			if (e->sideDistX < e->sideDistY)
			{
				e->sideDistX += e->deltaDistX;
				e->mapX += e->stepX;
				e->side = 0;
			}
			else
			{
				e->sideDistY += e->deltaDistY;
				e->mapY += e->stepY;
				e->side = 1;
			}
			if (e->tab[e->mapX][e->mapY] > 0)
				e->hit = 1;
		}

		if (e->side == 0)
			e->wallDist = fabs((e->mapX - e->rayPosX + (1 - e->stepX) / 2) / e->rayDirX);
		else
			e->wallDist = fabs((e->mapY - e->rayPosY + (1 - e->stepY) / 2) / e->rayDirY);
		e->lineH = abs((int)(SCREEN_Y / e->wallDist));

		e->drawStart = -(e->lineH) / 2 + SCREEN_Y / 2;
		e->drawEnd = e->lineH / 2 + SCREEN_Y / 2;
		if (e->drawStart < 0)
			e->drawStart = 0;
		if (e->drawEnd >= SCREEN_Y)
			e->drawEnd = SCREEN_Y - 1;

		//

		int		j;
		j = 0;
		while (j < e->drawStart)
		{
			mlx_pixel_put(e->mlx, e->win, i, j, RGB_SKY);
			j++;
		}
		while (e->drawStart < e->drawEnd)
		{
			mlx_pixel_put(e->mlx, e->win, i, e->drawStart, RGB_WALL_N);
			e->drawStart++;
			j++;
		}
		while (j < SCREEN_Y)
		{
			mlx_pixel_put(e->mlx, e->win, i, j, RGB_FLOOR);
			j++;
		}
		i++;
	}
}

int     expose_hook(t_env *e)
{
    draw(e);
    return (0);
}

int     key_hook(int keycode, t_env *e)
{
    if (keycode == 65307)
        exit(1);
	if (keycode == 119)
	{
		if (e->tab[(int)(e->posX + e->dirX)][(int)(e->posY)] == 0)
			e->posX += e->dirX;
		if (e->tab[(int)(e->posX)][(int)(e->posY + e->dirY)] == 0)
			e->posY += e->dirY;
	}
	if (keycode == 115)
    {
		if (e->tab[(int)(e->posX - e->dirX)][(int)(e->posY)] == 0)
            e->posX -= e->dirX;
		if (e->tab[(int)(e->posX)][(int)(e->posY - e->dirY)] == 0)
            e->posY -= e->dirY;
    }
	if (keycode == 97)
    {
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(-(0.5)) - e->dirY * sin(-(0.5));
		e->dirY = e->oldDirX * sin(-(0.5)) + e->dirY * cos(-(0.5));
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(-(0.5)) - e->planeY * sin(-(0.5));
		e->planeY = e->oldPlaneX * sin(-(0.5)) + e->planeY * cos(-(0.5));
    }
	if (keycode == 100)
    {
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos((0.5)) - e->dirY * sin((0.5));
		e->dirY = e->oldDirX * sin((0.5)) + e->dirY * cos((0.5));
        e->oldPlaneX = e->planeX;
        e->planeX = e->planeX * cos((0.5)) - e->planeY * sin((0.5));
        e->planeY = e->oldPlaneX * sin((0.5)) + e->planeY * cos((0.5));
    }
    mlx_clear_window(e->mlx, e->win);
	draw(e);
    return (0);
}

int		main(int argc, char **argv)
{
	t_env		e;

	e.argc = argc;
    e.argv = argv;
	ft_nbr_line_col(&e);
    ft_stock_value(&e);
    e.posX = 2;
    e.posY = 2;
    e.dirX = 1;
    e.dirY = 0;
    e.planeX = 0;
    e.planeY = 0.66;
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, SCREEN_X, SCREEN_Y, "wolf3d");
	mlx_key_hook(e.win, key_hook, &e);
    mlx_expose_hook(e.win, expose_hook, &e);
    mlx_loop(e.mlx);
	return (0);
}
