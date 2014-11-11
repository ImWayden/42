/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 06:29:24 by atouzeau          #+#    #+#             */
/*   Updated: 2014/11/11 01:14:55 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

void	treat_image(t_param *param, char *file)
{
	int		ret;

	ret = get_scene(param, file);
	if (ret == -1)
		exit(0);
	rempli_img(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img, 0, 0);
}

void	init_libx(t_param *param, char *file)
{
	param->mlx_ptr = mlx_init();
	if (param->mlx_ptr == 0)
		ft_puterror("Can't init libx.\n");
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIN_X, WIN_Y, "Raytracer");
	param->img = mlx_new_image(param->mlx_ptr, WIN_X, WIN_Y);
	param->ppti.data = mlx_get_data_addr(param->img, &param->ppti.bpp,
		&param->ppti.sizeline, &param->ppti.endian);
	treat_image(param, file);
	mlx_key_hook(param->win_ptr, &key, &param);
	mlx_expose_hook(param->win_ptr, &expose, param);
	mlx_loop(param->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_param		param;

	if (argc == 2)
		init_libx(&param, argv[1]);
	else if (argc == 1)
		ft_putstr("Please select a configuration file.\n");
	else
		ft_putstr("Select just one configuration file.\n");
	return (0);
}
