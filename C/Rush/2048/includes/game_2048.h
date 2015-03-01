/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:56:20 by msarr             #+#    #+#             */
/*   Updated: 2015/02/27 20:56:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
#include <curses.h>
#include <term.h>
# include <ncurses.h>
# include "libft.h"

/*
** STRUCTS ENUM AND DEFINE
*/

#define ENTER		10
#define ESCAPE		27

typedef struct termios	t_term;

typedef struct	s_win
{
	int			val;
	WINDOW		*win;
}				t_win;

typedef struct	s_game
{
	int			win_h;
	int			win_w;
	int			startx;
	int			padx;
	int			starty;
	int			pady;
	int			size;
	WINDOW 		*menubar;
	WINDOW		*msgbar;
	WINDOW		*win;
	WINDOW		**menulist;	
	t_win		array[5][5];
}				t_game;




int 		menu(t_game *game);
int			setwins(t_game *game);
void		del_win(WINDOW **win);
void		del_menu(t_game *game);
int			padding(t_game *game);
int			ft_exit(char *str, t_game *game);

#endif