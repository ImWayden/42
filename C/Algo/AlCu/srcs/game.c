/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:27:40 by msarr             #+#    #+#             */
/*   Updated: 2014/03/09 09:27:30 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p4.h"

t_gameroom			*firstread(char **argv)
{
	int			*tab;

	tab = (int *)ft_memalloc(2);
	tab[0] = 6;
	tab[1] = 7;
	if (argv && argv[1] && argv[2] && isnbr(argv[1]) && isnbr(argv[2]))
	{
		tab[0] = ft_atoi(argv[1]);
		tab[1] = ft_atoi(argv[2]);
	}
	return (newgameroom(tab));
}

void				insert(t_gameroom *game, int i, int player)
{
	int 			j;

	j = (game->cord)[0] - 1;

	while ((game->tab)[j] && (game->tab)[j][i] != '-')
		j--;
	(game->tab)[j][i] = player;
	printroom(game->tab);
}

int 				rverif(t_gamemem *mem)
{
	if (mem)
	{
		if((mem->p)[0] != -1 && (mem->p)[1] != -1
							 && (mem->p1)[0] != -1 && (mem->p1)[1] != -1)
			return(1);
	}
	return (0);
}
void				haswin(t_gameroom *game, char c)
{
	if (checkobl(game, c) || checkiobl(game, c) || checkvert(game, c)
						  || checkhor(game, c))
	{
		if (c == '1')
			ft_putendl("YOU WIN !! CONGRATS.");
		if (c == '2')
			ft_putendl("I WIN !! TRY AGAIN.");
		exit(0);
	}
}

void				game(char	**argv)
{
	t_gameroom		*game;
	int				i;
	char			*str = NULL;

	game = firstread(argv);
	printroom(game->tab);
	while(42)
	{
		ft_putcolorstr("HUMAN : ", RED);
		getnextline(0, &str);
		if(!ft_strcmp("exit", str))
			exit(0);
		if (isnbr(str))
		{
			i = ft_atoi(str) - 1;
			if (verif(i, game))
			{
				insert(game, i, '1');
				haswin(game, '1');
				ft_putcolorstr("IA : \n", BLUE);
				player(game);
				haswin(game, '2');
			}
		}
	}
}
