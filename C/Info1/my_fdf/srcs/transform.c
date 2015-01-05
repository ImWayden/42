/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 18:44:13 by msarr             #+#    #+#             */
/*   Updated: 2014/10/11 23:04:52 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			transform(t_coord **tab)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j].z != -2)
		{
			x = tab[i][j].x;
			y = tab[i][j].y;
			if (tab[i][j].z)
				tab[i][j].z = tab[i][j].z / 20;
			tab[i][j].x = 0.71 * (x - y);
			tab[i][j].y = (-0.82 * tab[i][j].z + 0.41 * (x + y));
			j++;
		}
		i++;
	}
	return (1);
}
