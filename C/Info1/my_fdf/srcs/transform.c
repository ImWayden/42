/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 18:44:13 by msarr             #+#    #+#             */
/*   Updated: 2014/10/10 18:44:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			transform(t_coord **tab, int pad)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	while(tab[i])
	{
		j = 0;
		while (tab[i][j].z != -1)
		{
			x = tab[i][j].x;
			y = tab[i][j].y;
			ft_putnbr(tab[i][j].x);
			ft_putnbr(tab[i][j].y);
			ft_putnbr(tab[i][j].z);
			tab[i][j].x = 15 * 0.71 * (x - y) + pad;
			tab[i][j].y = 15 * ((0.41 * (x + y) - 0.82 * tab[i][j].z)) + pad;
			ft_putnbr(tab[i][j].x);
			ft_putnbr(tab[i][j].y);
			j++;
		}
		i++;
	}
	return (1);
}