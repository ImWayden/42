/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:16:25 by msarr             #+#    #+#             */
/*   Updated: 2015/04/11 13:16:28 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		get_color(t_env *env, t_cplx z, t_cplx a, size_t i)
{
	t_rgb	r;


	if (i == env->max_i)
		r = getcolor(z);
	else
		r = orbitrap(env, a, i);
	return (r);
}