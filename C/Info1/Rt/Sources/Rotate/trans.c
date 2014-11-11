/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:54:25 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 16:54:27 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

void	trans_spot(t_utils *utils, t_objet *obj)
{
	while (utils->spot != NULL)
	{
		utils->spot->coord.x -= obj->coord.x;
		utils->spot->coord.y -= obj->coord.y;
		utils->spot->coord.z -= obj->coord.z;
		utils->spot = utils->spot->next;
	}
}

void	trans_inv(t_utils *utils, t_objet *obj, int flag)
{
	t_spot *beg;

	beg = utils->spot;
	if (flag == 1 || flag == 0)
	{
		utils->coord.x -= obj->coord.x;
		utils->coord.y -= obj->coord.y;
		utils->coord.z -= obj->coord.z;
	}
	else if (flag == 2 || flag == 0)
		trans_spot(utils, obj);
	else if (flag == 3)
	{
		utils->vect.n_x -= obj->coord.x;
		utils->vect.n_y -= obj->coord.y;
		utils->vect.n_z -= obj->coord.z;
	}
	utils->spot = beg;
}

void	trans_nor(t_utils *utils, t_objet *obj, int flag)
{
	t_spot *beg;

	beg = utils->spot;
	if (flag == 1 || flag == 0)
	{
		utils->coord.x += obj->coord.x;
		utils->coord.y += obj->coord.y;
		utils->coord.z += obj->coord.z;
	}
	else if (flag == 2 || flag == 0)
		trans_spot(utils, obj);
	else if (flag == 3)
	{
		utils->vect.n_x += obj->coord.x;
		utils->vect.n_y += obj->coord.y;
		utils->vect.n_z += obj->coord.z;
	}
	utils->spot = beg;
}
