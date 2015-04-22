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

t_coeff		coeff()
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
	t_coeff	*c;

	if ((c = malloc(NCOEFF * sizeof(t_coeff))))
	{
		i = -1;
		while (++i < NCOEFF)
			c[i] = coeff();
	}
	return (c);
}