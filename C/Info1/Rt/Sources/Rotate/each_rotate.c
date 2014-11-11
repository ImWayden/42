/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   each_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:54:04 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 18:11:02 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

t_utils	*rot_pos(t_utils *utils, t_objet *objet, int flag)
{
	rotate_z(&utils->coord.x, &utils->coord.y,
		&utils->coord.z, objet->rot.rot_z * flag);
	rotate_y(&utils->coord.x, &utils->coord.y,
		&utils->coord.z, objet->rot.rot_y * flag);
	rotate_x(&utils->coord.x, &utils->coord.y,
		&utils->coord.z, objet->rot.rot_x * flag);
	return (utils);
}

t_utils	*rot_vector(t_utils *utils, t_objet *objet, int flag)
{
	rotate_z(&utils->vect.v_x, &utils->vect.v_y,
		&utils->vect.v_z, objet->rot.rot_z * flag);
	rotate_y(&utils->vect.v_x, &utils->vect.v_y,
		&utils->vect.v_z, objet->rot.rot_y * flag);
	rotate_x(&utils->vect.v_x, &utils->vect.v_y,
		&utils->vect.v_z, objet->rot.rot_x * flag);
	return (utils);
}

t_utils	*rot_spot(t_utils *utils, t_objet *objet, int flag)
{
	t_spot *beg;

	beg = utils->spot;
	while (utils->spot != NULL)
	{
		rotate_z(&utils->spot->coord.x, &utils->spot->coord.y,
			&utils->spot->coord.z, objet->rot.rot_z * flag);
		rotate_y(&utils->spot->coord.x, &utils->spot->coord.y,
			&utils->spot->coord.z, objet->rot.rot_y * flag);
		rotate_x(&utils->spot->coord.x, &utils->spot->coord.y,
			&utils->spot->coord.z, objet->rot.rot_x * flag);
		utils->spot = utils->spot->next;
	}
	utils->spot = beg;
	return (utils);
}

t_utils	*norm_rotate(t_utils *utils, t_objet *objet, int flag)
{
	rotate_z(&utils->vect.n_x, &utils->vect.n_y,
		&utils->vect.n_z, objet->rot.rot_z * flag);
	rotate_y(&utils->vect.n_x, &utils->vect.n_y,
		&utils->vect.n_z, objet->rot.rot_y * flag);
	rotate_x(&utils->vect.n_x, &utils->vect.n_y,
		&utils->vect.n_z, objet->rot.rot_x * flag);
	return (utils);
}

t_utils	*rot_eye(t_utils *utils)
{
	rotate_z(&utils->vect.v_x, &utils->vect.v_y,
		&utils->vect.v_z, utils->eye_rot.rot_z);
	rotate_y(&utils->vect.v_x, &utils->vect.v_y,
		&utils->vect.v_z, utils->eye_rot.rot_y);
	rotate_x(&utils->vect.v_x, &utils->vect.v_y,
		&utils->vect.v_z, utils->eye_rot.rot_x);
	return (utils);
}
