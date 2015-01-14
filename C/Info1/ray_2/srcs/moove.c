/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2015/01/01 12:49:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

int				forward(t_env *env)
{
	t_vect		colis;
	t_vect		colis1;

	colis = add(mult2(env->cam.dir, 0.5), env->cam.pos);
	colis1 = add(mult2(env->cam.dir, 0.5), env->cam.lookat);
	put_vect("pos", env->cam.pos);
	put_vect("pos n", colis);
	put_vect("look", env->cam.lookat);
	put_vect("dir n", colis1);
	env->cam.pos = colis;
	env->cam.lookat = colis1;
	cam_setup(&env->cam);
	return (1);
}

