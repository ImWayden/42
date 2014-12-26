/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 20:51:04 by msarr            ###   ########.fr       */
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
	c->upright = cross(c->up, c->dir);
	// De meme pour le "vrai" vecteur haut.
	c->up = cross(c->dir, c->upright);
	// Maintenant nous avons toutes les informations pour détérminer la position 
	// en haut à gauche du viewplane.
	c->upleft
	//cam_setup(&env->cam);
	return (1);
}

