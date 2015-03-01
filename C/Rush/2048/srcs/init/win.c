/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setgame->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:02:16 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 21:02:16 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			padding(t_game *game)
{
	int		i;
	int		h;
	int		w;

	i = 1;
	h = game->win_h - 3;
	w = game->win_w * 2.5;
	while ((h > game->size * i) && (w > game->size * i))
		i++;
	if (--i >= 4)
	{
		game->padx = 2.5 * i;
		game->pady = i;
		return (1);
	}
	game->win_h += 3;
	return (ft_exit("Window too small.", game));
}

static int	create_wins(t_game *game)
{
	game->menubar = newwin(1, game->win_w, 0, 0);
	game->msgbar = newwin(2, game->win_w, game->win_h - 2, 0);
	game->starty = 1;
	game->startx = 0;
	game->win = newwin(game->win_h - 3, game->win_w, game->starty, game->startx);
	wbkgd(game->menubar, COLOR_PAIR(2));
	waddstr(game->menubar, "Menu");
	wattron(game->menubar, COLOR_PAIR(3));
	waddstr(game->menubar, "(F1)");
	wattroff(game->menubar, COLOR_PAIR(3));
	waddstr(game->msgbar,"Press F1 to open the menu, ESC to quit.");
	wbkgd(game->win, COLOR_PAIR(2));
	box(game->win, ACS_VLINE, ACS_HLINE);
	wrefresh(game->menubar);
	wrefresh(game->msgbar);
	wrefresh(game->win);
	refresh();
	return (1);
}

int					setwins(t_game *game)
{
	struct winsize	win;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &win) != -1)
	{
		game->win_w = win.ws_col;
		game->win_h = win.ws_row;
		create_wins(game);
		return (1);
	}
	return (0);
}