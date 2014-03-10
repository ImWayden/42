/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:45:40 by msarr             #+#    #+#             */
/*   Updated: 2014/03/09 12:45:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p4.h"

void			printroom(char **str)
{
	int 		i;
	int 		j;

	i = 0;
	while (str && str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if(str[i][j] == '-')
				ft_putcolorstr("▀", GREY);
			if(str[i][j] == '1')
				ft_putcolorstr("▀", RED);
			if(str[i][j] == '2')
				ft_putcolorstr("▀", BLUE);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

t_gameroom		*newgameroom(int tab[2])
{
	t_gameroom	*game;
	int			i;

	game = (t_gameroom *)malloc(sizeof(t_gameroom));
	game->tab = (char **)malloc(sizeof(char *) * (tab[0] + 1));
	game->cord = (int *)malloc(sizeof(int) * 2);
	(game->tab)[tab[0]] = NULL;
	game->cord[0] = tab[0];
	game->cord[1] = tab[1];
	i = 0;
	while (i < tab[0])
	{
		(game->tab)[i] = (char *)malloc(sizeof(char) * (tab[1] + 1));
		(game->tab)[i][tab[1]] = '\0';
		ft_memset((game->tab)[i], '-', tab[1]);
		i++;
	}
	return (game);
}
