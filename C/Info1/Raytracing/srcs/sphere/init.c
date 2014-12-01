/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 22:51:08 by msarr             #+#    #+#             */
/*   Updated: 2014/11/28 23:41:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

t_vect			*new_vect(t_vect tmp)
{
	t_vect		*vect;

	if ((vect = (t_vect *)malloc(sizeof(t_vect))))
	{
		vect->x = tmp.x;
		vect->y = tmp.y;
		vect->z = tmp.z;
	}
	return (vect);
}