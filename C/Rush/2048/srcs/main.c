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

static void		init(t_game game)
{
	initscr();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    curs_set(0);
    noecho();
    keypad(stdscr,TRUE);
    bkgd(COLOR_PAIR(1));
    game.menubar = subwin(stdscr, 1, 10, 0, 0);
    game.msgbar = subwin(stdscr, 1, 79, 23, 1);
    wbkgd(game.menubar,COLOR_PAIR(2));
	waddstr(game.menubar,"Menu");
	wattron(game.menubar,COLOR_PAIR(3));
	waddstr(game.menubar,"(F1)");
	wattroff(game.menubar,COLOR_PAIR(3));
    move(2,1);
    printw("Press F1 to open the menu. ");
    printw("ESC quit.");
    refresh();
}

int			main(int ac, char **av)
{
	t_game	game;
	int 	key;

	(void)av;
	if (ac == 1)
	{
		if (!term() || !setwin(game))
			return (0);
			//ft_exit("Game_2048: Initialisation failed.", game);
		init(game);
		key = -1;
		while (key!= ESCAPE)
		{
			key = getch();
			if (key == KEY_F(1) && menu(game) > 0)
			{
					//play(game);
				return (0);
			}
		}
	}
	else
		ft_putendl("Game_2048: Initialisation failed.");
	return 0;
}