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


typedef struct s_env
{
	void	*mlx;
	void	*win;
	char	*str;
}				t_env;

typedef struct e_point
{
	int 	x;
	int		y;
}				t_point;

void	draw(t_env *e, t_point *point)
{
	int 	x;
	int 	y;

	y = point->y;
	while (y < (point->y + 10))
	{
		x = point->x;
		while (x < (point->x + 10))
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
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
			write(1, "\n", 1);
			point.y = point.y + 10;
			point.x = 0;
		}
		else
		{
			write(1, &buff[0], 1);
			draw(e, &point);
			point.x = point.x + 10;
		}
	}
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
	t_env	e;
	t_point poit1,point2;

	e.mlx = mlx_init();
	e.str = argv[1];
	e.win = mlx_new_window(e.mlx, 420, 420, "Negusse");
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return 0;
}