/* ************************************************************************** */
/*																																													 */
/*																																	 :::			 ::::::::   */
/*   funct.c																								    :+:			 :+:    :+:   */
/*																														  +:+ +:+			    +:+			*/
/*   By: msarr <msarr@student.42.fr>									 +#+  +:+			  +#+			   */
/*																											   +#+#+#+#+#+   +#+						 */
/*   Created: 2015/01/26 14:06:45 by msarr						   #+#    #+#						   */
/*   Updated: 2015/01/26 14:06:45 by msarr						  ###   ########.fr			  */
/*																																													 */
/* ************************************************************************** */

#include "fractol.h"

/*
** 00 : Linear
*/

void			linear(t_env *env, double x, double y) 
{
	double		r;
	double		theta;

	r = sqrt (x * x + y * y) * M_PI;
	theta = atan2 (y, x) / M_PI;
	env->z.r = theta * sin (r);
	env->z.i = theta * cos (r);
}

/*
** 01 : Sinusoidal
*/

