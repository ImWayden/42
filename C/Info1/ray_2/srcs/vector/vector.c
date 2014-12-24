/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:13:38 by msarr             #+#    #+#             */
/*   Updated: 2014/12/24 16:58:14 by msarr            ###   ########.fr       */
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
	if ((d = sqrt(dot(v, v))))
	{
		v.x /= d;
		v.z /= d;
		v.y /= d;
	}
	return (v);
}

t_vect		add2(t_vect a, t_vect b, t_vect c)
{
	return (new(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z));
}

double		dot(t_vect a, t_vect b)
{
	double	d;

	d = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (d);
}

t_vect		sub(t_vect a, t_vect b)
{
	t_vect	vect;

	vect.x = a.x - b.x;
	vect.y = a.y - b.y;
	vect.z = a.z - b.z;
	return (vect);
}

t_vect		mult2(t_vect v, double b)
{
	v.x *= b;
	v.y *= b;
	v.z *= b;
	return (v);
}

t_vect		divi(t_vect v, double b)
{
	v.x /= b;
	v.y /= b;
	v.z /= b;
	return (v);
}

double		length(t_vect v)
{
	double	d;

	d = dot(v, v);
	d = sqrt(d);
	return (d);
}

t_vect		unit(t_vect v)
{
	double is;

	if ((is = length(v)) > 1)
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
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
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
	t_vect	v;

	v.x = vect.x + vect1.x;
	v.y = vect.y + vect1.y;
	v.z = vect.z + vect1.z;
	return (v);
}

t_vect		mult(t_vect vect, t_vect vect1)
{
	return (new(vect1.x * vect.x, vect1.y * vect.y, vect1.z * vect.z));
}

t_vect		square(t_vect vect)
{
	return (new(vect.x * vect.x, vect.y * vect.y, vect.z * vect.z));
}
