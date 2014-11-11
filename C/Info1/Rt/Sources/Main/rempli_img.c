/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempli_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:53:16 by atouzeau          #+#    #+#             */
/*   Updated: 2014/11/11 01:18:15 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "rt.h"

t_k		anti_aliasing(int x, int y, t_param *param, t_k k)
{
	double	i;
	double	j;
	t_k		tmp;

	i = (double)x;
	init_k(&k);
	while (i < (double)(x + 1))
	{
		j = (double)y;
		while (j < (double)(y + 1))
		{
			init_k(&tmp);
			tmp = calc(i, j, param, &tmp);
			k.color.blue += tmp.color.blue;
			k.color.green += tmp.color.green;
			k.color.red += tmp.color.red;
			j += 1.0 / param->anti_alias;
		}
		i += 1.0 / param->anti_alias;
	}
	k.color.red = k.color.red / SQ(param->anti_alias);
	k.color.blue = k.color.blue / SQ(param->anti_alias);
	k.color.green = k.color.green / SQ(param->anti_alias);
	k.k = tmp.k;
	return (k);
}

void	set_aa(t_param *param)
{
	if (param->anti_alias < 1.0)
		param->anti_alias = 1.0;
	if (param->anti_alias > 4.0)
		param->anti_alias = 4.0;
}

void	rempli_img(t_param *param)
{
	int		x;
	int		y;
	t_k		k;

	ft_putstr("Please wait...\n");
	count_obj(param);
	set_aa(param);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		while (++x < WIN_X)
		{
			k = anti_aliasing(x, y, param, k);
			if (k.k >= 0)
				mlx_ppti(x, y, param, &k);
		mlx_string_put(param->mlx_ptr, param->win_ptr, 500, 500, 0x33ff33, \
						(ft_strjoin("Chargement : ", ft_strjoin(ft_itoa( \
						(double)y / (double)WIN_Y * 100), "%."))));
		}
	}
	ft_putstr("Done\n");
}
