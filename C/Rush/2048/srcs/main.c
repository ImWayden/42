/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:34:44 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 21:34:44 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	init(t_game *game)
{
	game->menubar = NULL;
	game->win = NULL;
	game->msgbar = NULL;
	game->menulist = NULL;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	bkgd(COLOR_PAIR(1));
	refresh();
}

void	set_plateau(t_game *game)
{
	int 	i;
	int 	j;

	i = 0;
	padding(game);
	while (i < game->size)
	{
		j = 0;
		while (j < game->size)
		{
			game->array[i][j].val = 0;
			game->array[i][j].win = subwin(game->win , game->pady, game->padx, game->starty, game->startx);
			box(game->array[i][j].win, ACS_VLINE, ACS_HLINE);
			wrefresh(game->array[i][j].win);
			refresh();
			sleep (1);
			game->startx += game->padx;
			j++;
		}
		i++;
		game->startx = 0;
		game->starty += game->pady;
	}
	refresh();
}

int			main()
{
	t_game	game;

	if (initscr())
	{
		init(&game);
		setwins(&game);
		if ((game.size = menu(&game) + 3) > 3)
			set_plateau(&game);
		sleep(10);
		endwin();
	}
	else
		ft_putendl("Game_2048: Initialisation failed.");
		return 0;
}