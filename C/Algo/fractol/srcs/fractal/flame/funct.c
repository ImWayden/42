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

	r = x * x + y * y;
	env->z.r = x * sin(r) - y * cos(r);
	env->z.i = x * cos(r) + y * sin(r);
}

/*
** 01 : Sinusoidal
*/


