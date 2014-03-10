/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:50:28 by msarr             #+#    #+#             */
/*   Updated: 2014/03/09 15:50:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p4.h"

int			checkobl(t_gameroom *game, char c)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (i < (game->cord)[0] && j < (game->cord)[1])
	{
		if (while1(game, c, i, j))
			return(1);
		if (i == (game->cord)[0] - 1)
			j++;
		else
			i++;
	}
	return 0;
}

int			checkiobl(t_gameroom *game, char c)
{
	int 	i;
	int 	j;

	i = 0;
	j = (game->cord)[1] - 1;
	while (i < (game->cord)[0] && j >= 0)
	{
		if (while1(game, c, i, j))
			return(1);
		if (j)
			j--;
		else
			i++;
	}
	return 0;
}

int			checkhor(t_gameroom *game, char c)
{
	int 	i;
	int 	j;
	int 	k;


	i = 0;
	while (i < (game->cord)[0])
	{
		j = 0;
		k = 0;
		while (j < (game->cord)[1] && i < (game->cord)[1])
		{
			if ((game->tab)[i][j] == c)
				k++;
			else
				k = 0;
			if (k == 4)
				return (k);
			j++;
		}
		i++;
	}
	return 0;
}

int				checkvert(t_gameroom *game, char c)
{
	int 			i;
	int 			j;
	int 			k;

	i = 0;
	j = 0;
	while (i < (game->cord)[1])
	{
		j = 0;
		k = 0;
		while (j < (game->cord)[0])
		{
			if ((game->tab)[j][i] == c)
				k++;
			else
				k = 0;
			if (k == 4)
				return (k);
			j++;
		}
		k = 0;
		i++;
	}
	return (0);
}