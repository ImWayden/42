/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   	background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 15:40:30 by msarr             #+#    #+#             */
/*   Updated: 2015/04/07 15:40:33 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx			(*background(int i))(t_coeff, double, double)
{
	t_cplx	(*	back[40])(t_coeff, double, double);
	
	back[0] = linear;
	back[1] = sinusoidal;
	back[2] = spherical;
	back[3] = swirl;
	back[4] = horseshoe;
	back[5] = polar;
	back[6] = handker;
	back[7] = heart;
	back[8] = disk;
	back[9] = spiral;
	back[10] = hyper;
	back[11] = diamond;
	back[12] = f_exp;
	back[13] = f_julia;
	back[14] = bent;
	back[15] = waves;
	back[16] = fisheye;
	back[17] = popcorn;
	back[18] = exponential;
	back[19] = power;
	back[20] = cosine;
	back[21] = rings;
	back[22] = fan;
	back[23] = blob;
	back[24] = pdj;
	back[25] = fan2;
	back[26] = rings2;
	back[27] = eyefish;
	back[28] = bubble;
	back[29] = cylinder;
	back[30] = noise;
	back[31] = blur;
	back[32] = curl;
	back[33] = tangent;
	back[34] = square;
	back[35] = cross;
	back[36] = collatz;
	return (back[i - 1]);
}