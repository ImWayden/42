/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:52:51 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:05:24 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<mlx.h>
#include	<stdlib.h>
#include	"rt.h"

int		expose(t_param *param)
{
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
	param = param;
	return (0);
}

int		key(int bouton, t_param **param)
{
	if (bouton == 65307)
	{
		mlx_destroy_window((*param)->mlx_ptr, (*param)->win_ptr);
		free_list(*param);
		exit(0);
	}
	param = param;
	return (0);
}
