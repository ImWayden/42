/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 18:49:24 by msarr             #+#    #+#             */
/*   Updated: 2014/03/09 18:49:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p4.h"

int					isnbr(char *str)
{
	while (str && *str && ft_isdigit(*str))
		str++;
	if (str && !(*str))
		return (1);
	else
		return (0);
}

int					verif(int i, t_gameroom *game)
{
	if (i >= 0 && i < (game->cord)[1] && (game->tab)[0][i] == '-')
			return (1);
	else
		return (0);
}

int					while1(t_gameroom *game, char c, int i, int j)
{
	int				x;
	int				y;
	int				k;

	x = i;
	y = j;
	k = 0;
	while (y < (game->cord)[1] && x >= 0)
	{
		if ((game->tab)[x][y] == c)
			k++;
		else
			k = 0;
		if (k == 4)
			return (k);
		y--;
		x--;
	}
	return (0);
}

int					while2(t_gameroom *game, char c, int i, int j)
{
	int				x;
	int				y;
	int				k;
	
	x = i;
	y = j;
	k = 0;
	while (x < (game->cord)[0] && j < (game->cord)[1])
	{
		if ((game->tab)[x][y] == c)
			k++;
		else
			k = 0;
		if (k == 4)
			return (k);
		x++;
		y++;
	}
	return (0);
}