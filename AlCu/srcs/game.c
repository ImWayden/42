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
	(game->tab)[tab[0]] = NULL;
	game->cord = tab;
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

t_gameroom		*firstread(char **argv)
{
	int			*tab;

	tab = (int *)ft_memalloc(2);
	tab[1] = 7;
	tab[0] = 6;
	if (argv && argv[1] && argv[2] && isnbr(argv[1]) && isnbr(argv[2]))
	{
		tab[0] = ft_atoi(argv[1]);
		tab[1] = ft_atoi(argv[2]);
	}
	return (newgameroom(tab));
}

int			verif(int *tab, t_gameroom *game)
{
	if (tab[0] && tab[1] && --(tab[0]) <= (game->cord)[0] 
	&& --(tab[1]) <= (game->cord)[1] && (game->tab)[tab[0]][tab[1]] == '-')
			return (1);
	else
		return (0);
}
void		game(char	**argv)
{
	t_gameroom		*game;
	int				tab[2];
	char			*str = NULL;
	char			**split;

	game = firstread(argv);
	printroom(game->tab);
	while(getnextline(0, &str))
	{
		split = ft_strsplit(str, ' ');
		if (split && split[0] && split[1] && isnbr(split[0]) && isnbr(split[1]))
		{
			tab[0] = ft_atoi((ft_strsplit(str, ' '))[0]);
			tab[1] = ft_atoi((ft_strsplit(str, ' '))[1]);
			if (verif(tab, game))
				printroom(game->tab);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc)
		game(argv);
	return 0;
}
