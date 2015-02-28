/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:02:16 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 21:02:16 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int					setwin(t_game game)
{
	struct winsize	win;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &win) != -1)
	{
		game.win_w = win.ws_col;
		game.win_h = win.ws_row;
		(void)game;
		return (1);
	}
	return (0);
}