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
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_WHITE);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    bkgd(COLOR_PAIR(1));
    game.menubar = subwin(stdscr, 1, 10, 0, 0);
    game.msgbar = subwin(stdscr, 1, 79, 23, 1);
    wbkgd(game.menubar, COLOR_PAIR(2));
	waddstr(game.menubar, "Menu");
	wattron(game.menubar, COLOR_PAIR(3));
	waddstr(game.menubar, "(F1)");
	wattroff(game.menubar, COLOR_PAIR(3));
    move(2,1);
    printw("Press F1 to open the menu. ");
    printw("ESC quit.");
    refresh();
}

int 		padding(t_game game)
{
	int i;

	i = 1;
	while ((game.win_h > game.size * i) && (game.win_w > game.size * i) && i < 20)
		i++;
	return (--i);
}
void		draw(t_game game)
{
	//int 	i;
	//int 	j;
	int 	p;
	int 	startx;
	int 	starty;


	game.size += 3;
	game.win_h -= 2;
	p = padding(game);
	starty = (game.win_h - (game.size * p)) / 2; 
	startx = (game.win_w - (game.size * p)) / 2;
	p = game.size * p;
	printw("%i", p);
	game.win = newwin(p, p * 2.5, starty, startx);
	wbkgd(game.win, COLOR_PAIR(2));
	box(game.win, ACS_VLINE, ACS_HLINE);
	wrefresh(game.win);
    refresh();
    sleep(10);
	/*i = 0;
	while (i < game.size)
	{
		j = 0;
		while (j < game.size)
		{
			game.array[i][j].val = 0;
			game.array[i][j].win = subwin(game.win , p, p, starty, startx);
			startx += p;
			j++;
		}
		i++;
		startx = (game.win_w - (game.size * p)) / 2;
		starty += p;
	}*/
	refresh();
}

int			main(int ac, char **av)
{
	t_game	game;

	(void)av;
	if (initscr())
	{
		if (ac == 1)
		{
			if (!term())
				return (0);
			game = setwin(game);
			init(game);
			if ((game.size = menu(game)))
				draw(game);
		}
		else
			ft_putendl("Game_2048: Initialisation failed.");
	}
	else
		return (0);
	//delwin(game.menubar);
    //delwin(game.msgbar);
    endwin();
	return 0;
}