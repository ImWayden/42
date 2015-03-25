/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:12:55 by msarr             #+#    #+#             */
/*   Updated: 2015/03/23 15:12:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 			ft_exit(t_env *env, char *str)
{
	ft_memdel((void **)&env->color);
	ft_memdel((void **)env->pixel);
	ft_memdel((void **)env->coeff);
	ft_memdel((void **)env->t);
	ft_putstr("Fractol : ");
	ft_putendl(str);
	exit(0);
}