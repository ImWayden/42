/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 13:02:32 by msarr            ###   ########.fr       */
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
	static double	moveSpeed = 0.005;
	static double	rotSpeed = 0.0005;
	
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
int		ft_create_img(t_env *env)
{
	t_img *img;

	env->img[10] = (t_img *)malloc(sizeof(t_img));
	img = env->img[10];
	if (!(img->img = mlx_new_image(env->ptr, screenWidth, screenHeight)))
		exit (0);
	if (!(img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sizel), &(img->endian))))
		exit (0);
	return (1);
}

int 		ft_get_tex(t_env *env)
{
	t_img *img;
	int i;
	char	*tab[4];
	int			x2;
	int			y2;

	tab[0] = "map/SKY4.xpm";
	tab[1] = "map/Brownweave1.xpm";
	tab[2] = "map/Brownweave2.xpm";
	//tab[3] = "map/wall1.xpm";
	/*tab[4] = "map/wall4.xpm";
	tab[5] = "map/Rocky.xpm";
	tab[6] = "map/tomb.xpm";
	tab[7] = "map/wall2.xpm";
	tab[8] = "map/wall5.xpm";*/
	i = 0;
	while (i < 3)
	{
		x2 = 0;
		y2 = 0;
		env->img[i] = (t_img *)malloc(sizeof(t_img));
		img = env->img[i];
		ft_putendl(tab[i]);
		if (!(img->img = mlx_xpm_file_to_image(env->ptr, tab[i], &x2, &y2)))
			exit(0);
		if (!(img->data = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->sizel), &(img->endian))))
			exit(0);
		i++;
	}
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
	ft_create_img(&env);
	ft_putendl("img ok");
	ft_get_tex(&env);
	ft_putendl("texture ok");
	ft_putendl("texture ok");
	env.posX = 22;
	ft_putendl("texture 1");
	env.posY = 11.5;
	ft_putendl("texture 2");
	env.dirX = -1.0;
	ft_putendl("texture 3");
	env.dirY = 0.0;
	ft_putendl("texture 4");
	env.planeX = 0.0;
	ft_putendl("texture 5");
	env.planeY = 0.66;
	ft_putendl("texture 6");
	ft_putendl("get_start");		
	get_map(&env.worldMap, argv[1]);
	ft_putendl("get");		
	mlx_expose_hook(env.win, raycaster, &env);
		mlx_do_key_autorepeatoff(env.ptr);
		mlx_hook(env.win, KeyPress, KeyPressMask, ft_key_press, &env);
		mlx_hook(env.win, KeyRelease, KeyReleaseMask, ft_key_release, &env);
		mlx_mouse_hook(env.win, ft_mouse_hook, &env);
		mlx_loop_hook(env.ptr, ft_key_hook, &env);
		mlx_loop(env.ptr);
	return (0);
}
		
