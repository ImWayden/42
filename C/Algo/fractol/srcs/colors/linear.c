/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:45:12 by msarr             #+#    #+#             */
/*   Updated: 2015/02/02 13:45:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

// Imprecise method which does not guarantee v = v1 when t = 1,
// due to floating-point arithmetic error.
t_rgb		linear_inter(t_rgb v0, t_rgb v1, double t)
{
	return (rgb_add(v0, rgb_mult(rgb_sub(v1, v0), t)));
}
 
// Precise method which guarantees v = v1 when t = 1.
float lerp(float v0, float v1, float t) {
  return (1-t)*v0 + t*v1;
}