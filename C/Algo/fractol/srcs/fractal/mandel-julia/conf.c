/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 12:36:58 by msarr             #+#    #+#             */
/*   Updated: 2015/01/25 12:36:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_real		new(float x, float y)
{
	t_real	c;

	c.r = x;
	c.i = y;
	return (c);
}

t_real		conf(int i)
{
	t_real  config[16];

	config[0] = new(0.0, 0.0);
	config[1] = new(0.0, 0.0);
	config[2] = new(-0.46, 0.57);
	config[3] = new(-0.595, -0.435);
	config[4] = new(-0.615, -0.43);
	config[5] = new(0.41, -0.19);
	config[6] = new(-0.925, 0.255);
	config[7] = new(0.4399, 0.175);
	config[8] = new(-0.74543, 0.11301);
	config[9] = new(-0.199, -0.66);
	config[10] = new(-0.135, -0.65);
	config[11] = new(0.21, -0.555);
	config[12] = new(0.235, -0.515);
	config[13] = new(-0.77, 0.08);
	config[14] = new(-0.41, -0.635);
	config[15] = new(-0.11, 0.6557);
	return (config[i]);
}
