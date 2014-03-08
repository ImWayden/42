/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:27:40 by msarr             #+#    #+#             */
/*   Updated: 2014/03/08 18:27:44 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p4.h"

int				isnbr(char *str)
{
	while (str && *str && ft_isdigit(*str))
		str++;
	if (str && !(*str))
		return (1);
	else
		return (0);
}

void			printroom(char **str)
{
	int 		i;

	i = 0;
	while (str && str[i])
	{
		ft_putendl(str[i]);
		i++;
	}
}

t_gameroom		*newgameroom(int *tab)
{
	t_gameroom	*game;
	int			i;

	game = (t_gameroom *)malloc(sizeof(t_gameroom));
	game->tab = (char **)malloc(sizeof(char *) * (tab[0] + 1));
	(game->tab)[tab[0]] = NULL;
	i = 0;
	while (i < tab[0])
	{
		ft_putendl("OK");
		(game->tab)[i] = (char *)malloc(sizeof(char) * (tab[1] + 1));
		(game->tab)[i][tab[1]] = '\0';
		ft_memset((game->tab)[i], '▀', tab[1]);
		i++;
	}
	return (game);
}

t_gameroom		*firstread(char **argv)
{
	int			tab[2];

	tab[1] = 7;
	tab[0] = 6;
	if (argv && argv[1] && argv[2] && isnbr(argv[1]) && isnbr(argv[2]))
	{
		tab[0] = ft_atoi(argv[1]);
		ft_putnbr(tab[0]);
		tab[1] = ft_atoi(argv[2]);
		ft_putnbr(tab[1]);
	}
	return (newgameroom(tab));
}
void		game(char	**argv)
{
	t_gameroom		*game;

	game = firstread(argv);
	printroom(game->tab);
}

int main(int argc, char **argv)
{
	if (argc)
		game(argv);
	return 0;
}
