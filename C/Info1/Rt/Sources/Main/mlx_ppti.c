/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ppti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:53:09 by atouzeau          #+#    #+#             */
/*   Updated: 2014/11/11 01:15:13 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rt.h"

void		mlx_ppti(int x, int y, t_param *param, t_k *k)
{
	short	color;

	color = (k->color.blue + k->color.green + k->color.red) / 3;
	if (BW_FILTER == 1)
	{
		k->color.blue = color;
		k->color.green = color;
		k->color.red = color;
	}
	if (SEPIA_FILTER == 1)
	{
		k->color.blue = color / 2 + 15;
		k->color.green = color / 2 + 90;
		k->color.red = color / 2 + 127;
	}
	param->ppti.data[(y * param->ppti.sizeline) +
						(x * (param->ppti.bpp / 8))] = k->color.blue;
	param->ppti.data[(y * param->ppti.sizeline) +
						(x * (param->ppti.bpp / 8)) + 1] = k->color.green;
	param->ppti.data[(y * param->ppti.sizeline) +
						(x * (param->ppti.bpp / 8)) + 2] = k->color.red;
}
