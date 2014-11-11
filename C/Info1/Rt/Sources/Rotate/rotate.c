/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:54:21 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 16:54:23 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		obj_rot(t_utils *utils, t_objet *list, int sens, int flag)
{
	if (flag == 0)
		utils = rot_eye(utils);
	else if (flag == 1 && list->type != SPHERE)
	{
		utils = rot_pos(utils, list, sens);
		utils = rot_vector(utils, list, sens);
	}
	else if (flag == 2 && list->type != SPHERE)
		utils = norm_rotate(utils, list, sens);
	return (0);
}
