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

int		get_map(int ***tab, char *file)
{
	char	*s;
	char	*tmp;
	int 	i;
	int 	j;
	int 	fd;

	fd = open(file, O_RDONLY);
	i = 0;
	*tab = (int **)malloc(sizeof(int *) * 24);
	while (get_next_line(fd, &s) && i < 24)
	{
		j = 0;
		tmp = s;
		(*tab)[i] = (int *)malloc(sizeof(int) * 24);
		while (j < 24)
		{
			if (ft_isdigit(*tmp))
			{
				(*tab)[i][j] = *tmp - 48;
				j++;
			}
			tmp++;
		}
		i++;
    }
  return (0);
}

int				ft_key_press(int keycode, t_env *env)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == UP)
		env->forward = 1;
	if (keycode == DOWN)
		env->back = 1;
	if (keycode == LEFT)
		env->left = 1;
	if (keycode == RIGHT)
		env->right = 1;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int					ft_key_release(int keycode, t_env *env)
{
	if (keycode == UP)
		env->forward = 0;
	if (keycode == DOWN)
		env->back= 0;
	if (keycode == LEFT)
		env->left = 0;
	if (keycode == RIGHT)
		env->right = 0;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int					ft_key_hook(t_env *env)
{		
	static double	moveSpeed = 0.05;
	static double	rotSpeed = 0.05;
	
	if (env->forward)
		forward(env, moveSpeed);
	if (env->back)
		back(env, moveSpeed);
	if (env->right)
		turn_right(env, rotSpeed);
	if (env->left)
		turn_left(env, rotSpeed);
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
	get_map(&env.worldMap, argv[1]);
		mlx_expose_hook(env.win, raycaster, &env);
		mlx_do_key_autorepeatoff(env.ptr);
		mlx_hook(env.win, KeyPress, KeyPressMask, ft_key_press, &env);
		mlx_hook(env.win, KeyRelease, KeyReleaseMask, ft_key_release, &env);
		mlx_mouse_hook(env.win, ft_mouse_hook, &env);
		mlx_loop_hook(env.ptr, ft_key_hook, &env);
		mlx_loop(env.ptr);
	return (0);
}
		
