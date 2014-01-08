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

typedef struct s_env
{
	void	*mlx;
	void	*win;
}				t_env;

typedef struct e_point
{
	int 	x;
	int		y;
}				t_point;


void	drawline(t_point *p1, t_point *p2, t_env *e)
{
	int 	x;

	x = p1->x;
	while (x < p2->x)
	{
		mlx_pixel_put(e->mlx, e->win, x, p1->y + ((p2->y - p1->y) * (x - p1->x)) / (p2->x - p1->x), 0xFF0000);
		x++;
	}
}

void	draw(t_env *e)
{
	int 	x;
	int 	y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

int 	expose_hook(t_env *e)
{
	draw(e);
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

int main(int argc, char const *argv[])
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "Negusse");
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return 0;
}