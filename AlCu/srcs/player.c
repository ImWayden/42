/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:27:29 by msarr             #+#    #+#             */
/*   Updated: 2014/03/08 18:27:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p4.h"

int				isempty(t_gameroom *game)
{
	int			i;
	int			j;
	char		**str;

	i = 0;
	str = game->tab;
	j = (game->cord)[1] / 2;
	while (str[i] && str[i][j] == '-')
		i++;
	if (str[i])
		return (0);
	else
		return (1);
}

int			playmeadle(t_gameroom *game, int j)
{
	int			i;

	i = (game->cord)[0] - 1;
	while (j && (game->tab)[i] && (game->tab)[i][(j / 2)] != '-'
							   && (game->tab)[i][(j / 2) + 1] != '-')
		i--;
	if (j && (game->tab)[i])
	{
		if ((game->tab)[i][(j / 2)] == '-')
			(game->tab)[i][(j / 2)] = '2';
		else
			(game->tab)[i][(j / 2) + 1] = '2';
		return (1);
	}
	return (-1);
}

int			block(t_gameroom *game, int j)
{
	int			i;

	i = (game->cord)[0] - 1;
	while (j && (game->tab)[i] && (game->tab)[i][(j / 2)] != '-'
							   && (game->tab)[i][(j / 2) + 1] != '-')
		i--;
	if (j && (game->tab)[i])
	{
		if ((game->tab)[i][(j / 2)] == '-')
			(game->tab)[i][(j / 2)] = '2';
		else
			(game->tab)[i][(j / 2) + 1] = '2';
		return (1);
	}
	return (-1);
}

void			player(t_gameroom *game)
{
	//playmem		*mem;
	playmeadle(game, ((game->cord)[1] - 1));
	printroom(game->tab);
}