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

typedef struct	s_game
{
	int			win_h;
	int			win_w;
	int			size;
	WINDOW 		*menubar;
	WINDOW 		**menulist;
	WINDOW		*msgbar;
	int			*aray;
}				t_game;


int			term(void);
int 		menu(t_game game);
int			setwin(t_game game);

#endif