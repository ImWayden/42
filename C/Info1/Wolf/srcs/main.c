/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/10/11 01:51:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf.h"

int		get_map(int **tab, char *file)
{
	char	*s;
	char	*tmp;
	int 	i;
	int 	j;
	int 	fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &s))
	{
		j = 0;
		tmp = s;
		tab[i] = (int *)malloc(sizeof(int) * 24);
		while (*tmp)
		{
			if (ft_isdigit(*tmp))
			{
				tab[i][j] = *tmp - 48;
				j++;
			}
			tmp++;
		}
		i++;
    }
  return (0);
}

int					ft_key_hook(int keycode, t_env *env)
{
	double			oldDirX;
	double			oldPlaneX;			
	static double	moveSpeed = 0.5;
	static double	rotSpeed = 0.05;

	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
	{
		if (!env->worldMap[(int)(env->posX + env->dirX * moveSpeed)][(int)(env->posY)]
		&& !env->worldMap[(int)(env->posX)][(int)(env->posY + env->dirY * moveSpeed)])
		{
			env->posX += env->dirX * moveSpeed;
			env->posY += env->dirY * moveSpeed;
		}
	}
	if (keycode == 65364)
	{
		if (!env->worldMap[(int)(env->posX - env->dirX * moveSpeed)][(int)(env->posY)]
	  		&& !env->worldMap[(int)(env->posX)][(int)(env->posY - env->dirY * moveSpeed)])
		{
	  		env->posX -= env->dirX * moveSpeed;
	  		env->posY -= env->dirY * moveSpeed;
	  	}
	}
	if (keycode == 65363)
	{
		oldDirX = env->dirX;
		env->dirX = env->dirX * cos(-rotSpeed) - env->dirY * sin(-rotSpeed);
		env->dirY = oldDirX * sin(-rotSpeed) + env->dirY * cos(-rotSpeed);
		oldPlaneX = env->planeX;
		env->planeX = env->planeX * cos(-rotSpeed) - env->planeY * sin(-rotSpeed);
		env->planeY = oldPlaneX * sin(-rotSpeed) + env->planeY * cos(-rotSpeed);
	}
	if (keycode == 65361)
	{
		oldDirX = env->dirX;
		env->dirX = env->dirX * cos(rotSpeed) - env->dirY * sin(rotSpeed);
		env->dirY = oldDirX * sin(rotSpeed) + env->dirY * cos(rotSpeed);
		oldPlaneX = env->planeX;
		env->planeX = env->planeX * cos(rotSpeed) - env->planeY * sin(rotSpeed);
		env->planeY = oldPlaneX * sin(rotSpeed) + env->planeY * cos(rotSpeed);
	}
	raycaster(env);
	return (0);
}

int				ft_mouse_hook(int button, int x, int y)
{
	ft_putstr("mouse : ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(" : ");
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}

int main(int ac, char **argv)
{
	t_env env;

	if (ac < 2)
		return (0); 
	if ((env.ptr = mlx_init()) == NULL)
			return (0);
	if ((env.win = mlx_new_window(env.ptr, screenWidth,screenHeight, "Raycaster")) == NULL)
			return (0);
	if (!(env.img = mlx_new_image(env.ptr, screenWidth, screenHeight)))
		return (0);
	if (!(env.data = mlx_get_data_addr(env.img, &(env.bpp), &(env.sizel), &(env.endian))))
		return (0);
	env.texture[0] = WHITE_2;
	env.texture[1] = RED_2;
	env.texture[2] = GREEN_2;
	env.texture[3] = YELLOW_2;
	env.texture[4] = BLUE_2;
	env.texture[5] = PURPLE_2;
	env.texture[6] = CYAN_2;
	env.texture[7] = GREY_2;
	env.posX = 22;
	env.posY = 11.5;
	env.dirX = -1.0;
	env.dirY = 0.0;
	env.planeX = 0.0;
	env.planeY = 0.66;
	get_map(env.worldMap, argv[1]);
	while (42)
	{
		mlx_key_hook(env.win, ft_key_hook, &env);
		mlx_mouse_hook(env.win, ft_mouse_hook, &env);
		mlx_expose_hook(env.win, raycaster, &env);

		mlx_loop(env.ptr);
	}
	return (0);
}
		
