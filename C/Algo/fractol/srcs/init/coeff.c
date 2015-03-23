/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coeff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 22:48:54 by msarr             #+#    #+#             */
/*   Updated: 2015/03/07 22:48:54 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	randing(double *a, double *d)
{
	int	i;

	i = 0;
	while (!i || (*a * *a + *d * *d) > 1)
	{
		*a = drand48();
		*d = RANDR(*a * *a, 1);
		if (random_bit())
			*d = -(*d);
		i++;
	}
}

static void	mapping (t_coeff *coeff)
{
	double	a;
	double	b;
	double	d;
	double	e;
	double	k;

	a = 0;
	b = 0;
	d = 0;
	e = 0;
	k = 0;
	while (!k || (a * a + b * b + d * d + e * e)
		> (1 + (a * e - d * b) * (a * e - d * b)))
	{
		randing(&a, &d);
		randing(&b, &e);
		k++;
	}
	coeff->ac = a;
	coeff->bc = b;
	coeff->cc = RANDR (-2, 2);
	coeff->dc = d;
	coeff->ec = e;
	coeff->fc = RANDR (-2, 2);
}

t_coeff		co()
{
	t_coeff	c;

	c.ac = RANDR (-1.5, 1.5);
	c.bc = RANDR (-1.5, 1.5);
	c.cc = RANDR (-1.5, 1.5);
	c.dc = RANDR (-1.5, 1.5);
	c.ec = RANDR (-1.5, 1.5);
	c.fc = RANDR (-1.5, 1.5);
	c.pa1 = RANDR (-2, 2);
	c.pa2 = RANDR (-2, 2);
	c.pa3 = RANDR (-2, 2);
	c.pa4 = RANDR (-2, 2);
	return (c);
}

t_coeff		*coeffmap(void)
{
	int		i;
	t_coeff	*coeff;

	if ((coeff = malloc(NCOEFF * sizeof(t_coeff))))
	{
		i = 0;
		while (i < 3)
		{
			coeff[i] = co();
			if (random_bit())
				mapping (&coeff[i]);
			i++;
		}
	}
	return (coeff);
}