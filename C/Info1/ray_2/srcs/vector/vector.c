/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:13:38 by msarr             #+#    #+#             */
/*   Updated: 2014/12/23 19:34:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

double		cosinus(double a)
{
	return (cos((double)(PI * a) / (double)180));
}

double		sinus(double a)
{
    return (sin((double)(PI * a) / (double)180));
}

t_vect		rot(t_vect v, t_vect r)
{
	double	tmp;

	tmp = v.y;
    r.x = (int)r.x % 360;
    if (r.x < 0)
    	r.x += 360;
    v.y = tmp * cosinus(r.x) - v.z * sinus(r.x);
    v.z = tmp * sinus(r.x) + v.z * cosinus(r.x);
	tmp = v.x;
	r.y = (int)r.y % 360;
    if (r.y < 0)
    	r.y += 360;
    v.x = tmp * cosinus(r.y) - v.z * sinus(r.y);
    v.z = tmp * sinus(r.y) + v.z * cosinus(r.y);
	tmp = v.x;
	r.z = (int)r .z % 360;
	if (r.z < 0)
    	r.z += 360;
    v.x = tmp * cosinus(r.z) - v.y *sinus(r.z);
    v.y = tmp * sinus(r.z) + v.y *cosinus(r.z);
    return (v);
}

t_vect		normal(t_vect v)
{
	double	d;

   d = 1 / sqrt(dot(v, v));
   return (mult2(v, d));
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
	return (sqrt(dot(v, v)));
}

t_vect		unit(t_vect v)
{
	double is;

	if ((is = length(v)))
		return (mult2(v, (double)(1/is)));
	else
		return (v);
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
