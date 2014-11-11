/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:30:10 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 22:30:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		tex(char **tab)
{
	tab[0] = "map/sky.xpm";
	tab[1] = "map/colorstone.xpm";
	tab[2] = "map/bluestone.xpm";
	tab[3] = "map/greystone.xpm";
	tab[4] = "map/redbrick.xpm";
	tab[5] = "map/wood.xpm";
	tab[6] = "map/pillar.xpm";
	tab[7] = "map/mossy.xpm";
	tab[8] = "map/eagle.xpm";
	tab[9] = "map/Rocky.xpm";
}

int				ft_get_tex(t_env *env)
{
	t_img		*img;
	int			i;
	char		*tab[9];
	int			x2;
	int			y2;

	tex(tab);
	i = 0;
	while (i < 10)
	{
		x2 = 0;
		y2 = 0;
		env->img[i] = (t_img *)malloc(sizeof(t_img));
		img = env->img[i];
		if (!(img->img = mlx_xpm_file_to_image(env->ptr, tab[i], &x2, &y2)))
			exit(0);
		if (!(img->data = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->sizel), &(img->endian))))
			exit(0);
		i++;
	}
	return (0);
}
