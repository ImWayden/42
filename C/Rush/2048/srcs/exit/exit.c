/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:54:57 by msarr             #+#    #+#             */
/*   Updated: 2015/03/01 09:54:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	del_win(WINDOW **win)
{
	if (win && *win)
	{
		delwin(*win);
		*win = NULL;
	}
}

void	del_menu(t_game *game)
{
	if (game->menulist)
	{
		del_win(&game->menulist[0]);
		del_win(&game->menulist[1]);
		del_win(&game->menulist[2]);
		ft_memdel((void **)&(game->menulist));
	}
}

int		ft_exit(char *str, t_game *game)
{
	del_win(&game->menubar);
	del_win(&game->win);
	del_win(&game->msgbar);
	endwin();
	ft_putstr("Game_2048: ");
	ft_putendl(str);
	exit(0);
}