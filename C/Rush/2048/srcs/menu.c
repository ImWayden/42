/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:41:07 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 22:41:07 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static WINDOW	**show_menubar(t_game game)
{
	game.menulist = (WINDOW **)malloc(sizeof(WINDOW *) * 4);
	game.menulist[0]= newwin(4, 19, 1, 0);
	wbkgd(game.menulist[0], COLOR_PAIR(2));
	box(game.menulist[0], ACS_VLINE, ACS_HLINE);
	game.menulist[1] = subwin(game.menulist[0], 1, 17, 2, 1);
	wprintw(game.menulist[1],"Grill 5X5");
	game.menulist[2] = subwin(game.menulist[0], 1, 17, 3, 1);
	wprintw(game.menulist[2],"GRILL 4X4");
	game.menulist[3] = NULL;
	wbkgd(game.menulist[1], COLOR_PAIR(1));
	wrefresh(game.menulist[0]);
	return (game.menulist);
}

void		del_menu(t_game game)
{
	if (game.menulist)
	{
		delwin(game.menulist[0]);
		delwin(game.menulist[1]);
		delwin(game.menulist[2]);
	}
}

int 		menu(t_game game)
{
	int key;
	int i;

	i = 1;
	game.menulist = NULL;
	key = -1;
	while (key != ESCAPE && key != ENTER)
	{
		key = getch();
		if (key == KEY_F(1))
		{
			game.menulist = show_menubar(game);
			while ((key = getch()) && (key == KEY_UP || key == KEY_DOWN))
			{
				wbkgd(game.menulist[i], COLOR_PAIR(2));
				wrefresh(game.menulist[i]);
				i = (i == 1) ? 2 : 1;
				wbkgd(game.menulist[i], COLOR_PAIR(1));
				wrefresh(game.menulist[i]);
			}
			if (key != ENTER)
				i = 0;
		}
		if (key == ESCAPE)
			i = 0;
	}
	del_menu(game);
	touchwin(stdscr);
	refresh();
	return (i);
}
