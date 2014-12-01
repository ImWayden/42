/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:13:38 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 03:27:02 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

double invsqrt_1(double y)
{
    double xhalf = ( double )0.5 * y;
    long long i = *( long long* )( &y );
    i = 0x5fe6ec85e7de30daLL - ( i >> 1 );//LL suffix for (long long) type for GCC
    y = *( double* )( &i );
    y = y * ( ( double )1.5 - xhalf * y * y );
    return y;
}

t_vect		add2(t_vect a, t_vect b, t_vect c)
{
	return (new(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z));
}

double		dot(t_vect a, t_vect b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vect		sub(t_vect a, t_vect b)
{
	return (new(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vect		mult2(t_vect v, double b)
{
	return (new(v.x * b, v.y * b, v.z * b));
}

t_vect		divi(t_vect v, double b)
{
	return (mult2(v, 1.0 / b));
}

double		length(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vect		unit(t_vect v)
{
	double is;

	is = invsqrt_1(v.x * v.x + v.y * v.y + v.z * v.z);
	return mult2(v, is);
}

t_vect		cross(t_vect a, t_vect b)
{
	t_vect	v;

	v.x = (a.y * b.z) - (b.y * a.z);
	v.y = (a.z * b.x) - (b.z * a.x);
	v.z = (a.x * b.y) - (b.x * a.y);
	return (v);
}

t_vect		negate(t_vect v)
{
	return (new(-v.x, -v.y, -v.z));
}

t_vect		new(int x, int y, int z)
{
	t_vect	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vect		dupl(t_vect tmp)
{
	return (new(tmp.x, tmp.y, tmp.z));
}

t_vect		add(t_vect vect, t_vect vect1)
{
	return (new(vect1.x + vect.x, vect1.y + vect.y, vect1.z + vect.z));
}

t_vect		mult(t_vect vect, t_vect vect1)
{
	return (new(vect1.x * vect.x, vect1.y * vect.y, vect1.z * vect.z));
}

t_vect		square(t_vect vect)
{
	return (new(vect.x * vect.x, vect.y * vect.y, vect.z * vect.z));
}
