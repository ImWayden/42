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

static void		show_menubar(t_game game)
{
	game.menulist = (WINDOW **)malloc(sizeof(WINDOW *) * 4);
	game.menulist[0]= newwin(4, 19, 1, 1);
	wbkgd(game.menulist[0], COLOR_PAIR(2));
	box(game.menulist[0], ACS_VLINE, ACS_HLINE);
	game.menulist[1] = subwin(game.menulist[0], 1, 17, 2, 1);
	wprintw(game.menulist[1],"Grill 5X5");
	game.menulist[2] = subwin(game.menulist[0], 1, 17, 3, 1);
	wprintw(game.menulist[2],"GRILL 4X4");
	game.menulist[3] = NULL;
	wbkgd(game.menulist[1],COLOR_PAIR(1));
	wrefresh(game.menulist[0]);
}

void		del_menu(t_game game)
{
	delwin(game.menulist[0]);
	delwin(game.menulist[1]);
	delwin(game.menulist[2]);
}

int 		menu(t_game game)
{
	int key;
	int i;

	i = 1;
	show_menubar(game);
	move(3,1);
    printw("Press F1 to open the menu. ");
	while (42)
	{
		key = getch();
		if ((key == KEY_DOWN || key == KEY_UP) && game.menulist)
		{
			// wbkgd(game.menulist[i], COLOR_PAIR(2));
			// wnoutrefresh(game.menulist[i]);
			// i = (i == 1) ? 2 : 1;
			// wbkgd(game.menulist[i],COLOR_PAIR(1));
			// wnoutrefresh(game.menulist[i]);
			// doupdate();
		}
		else
			break;
	}
	//del_menu(game);
	return (1);
}
