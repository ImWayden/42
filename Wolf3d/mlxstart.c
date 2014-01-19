/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 13:40:29 by msarr             #+#    #+#             */
/*   Updated: 2014/01/08 13:40:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define GREEN 0x7FDD4C
#define BROWN 0xA76726
#define YELLOW 0xF0C300
#define RED 0xFF0000
#define BLUE 0x2C75FF

typedef struct s_env
{
	void	*mlx;
	void	*win;
	char	*str;
}				t_env;

typedef struct s_point
{
	int 	x;
	int		y;
}				t_point;

typedef struct s_player
{
	int 	high;
	int		view;
	t_point	point;
	int 	projangle;
}				t_player;

typedef struct s_project
{
	int 	dim;
	int		center;
	int 	dist;
	int 	angle;
}				t_project;

void	draw(t_env *e, t_point *point, int color)
{
	int 	x;
	int 	y;

	y = point->y;
	while (y < (point->y + 10))
	{
		x = point->x;
		while (x < (point->x + 10))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, color);
			x++;
		}
		y++;
	}
}


void	drawmap(t_env *e)
{
	int 	fd;
	char	buff[2];
	t_point point;

	fd = open(e->str, O_RDONLY);
	point.y = 0;
	point.x = 0;
	while (read(fd, buff, 1))
	{
		if (buff[0] == '\n')
		{
			point.y = point.y + 10;
			point.x = 0;
		}
		else
		{
			if (buff[0] == '0' || buff[0] == ' ')
				draw(e, &point, RED);
			else
				draw(e, &point, GREEN);
			point.x = point.x + 10;
		}
	}
}

t_point		*findinterhor(t_project *project, t_player *player)
{
	t_point		*point;

	if (player->projangle > 0)
		point->y = (player->point.y / 64) * 64 - 1;
	if (player->projangle < 0)
		point->y = (player->point.y / 64) * 64 + 64;
	point->x = player->point.x + (player->point.y - point->y) / tan(player->projangle);
	return (point);
}

t_point		*findinterver(t_project *project, t_player *player)
{
	t_point		*point;

	if (player->projangle < 90)
		point->x = (player->point.x / 64) * 64 + 64;
	if (player->projangle > 90)
		point->x = (player->point.x / 64) * 64 - 1;
	point->y = player->point.y + (player->point.y) * tan(player->projangle);
	return (point);
}

int 	expose_hook(t_env *e)
{

	drawmap(e);
	return (0);
}

int 	key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int 	mouse_hook(int button, int x, int y, t_env *e)
{
	printf("key: %d (%d %d)\n", button, x, y);
	return (0);
}

int main(int argc, char **argv)
{
	t_env		e;
	t_point 	poit1,point2;
	t_player	player;
	t_project	project;

	player.view = 60;
	player.high = 32;
	player.projangle = 45;
	project.dim = 320 * 200;
	project.center = 160;
	project.dist = 277;
	project.angle = 60 / 320;
	e.mlx = mlx_init();
	e.str = argv[1];
	e.win = mlx_new_window(e.mlx, 320, 200, "Negusse");
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return 0;
}