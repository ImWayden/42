/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 16:59:41 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 17:00:18 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

t_k		*turn_to_black(t_k *k)
{
	k->color.red = 0;
	k->color.green = 0;
	k->color.blue = 0;
	return (k);
}

t_k		*chess(t_objet obj3, t_k *k)
{
	if ((obj3.coord.x >= 0.0 && obj3.coord.y >= 0.0) ||
		(obj3.coord.x < 0.0 && obj3.coord.y < 0.0))
	{
		if (((int)ABS(obj3.coord.x) % 100 <= 50 &&
			(int)ABS(obj3.coord.y) % 100 <= 50) ||
			((int)ABS(obj3.coord.x) % 100 > 50 &&
			(int)ABS(obj3.coord.y) % 100 > 50))
			k = turn_to_black(k);
	}
	else
	{
		if (((int)ABS(obj3.coord.x) % 100 <= 50 &&
			(int)ABS(obj3.coord.y) % 100 <= 50) ||
			((int)ABS(obj3.coord.x) % 100 > 50 &&
			(int)ABS(obj3.coord.y) % 100 > 50))
			k = k;
		else
			k = turn_to_black(k);
	}
	return (k);
}
