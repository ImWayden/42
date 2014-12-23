/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:00:45 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 22:46:16 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETLINE_H
# define GETLINE_H

# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <dirent.h>
# include "minishell3.h"

typedef struct termios		t_termios;

void						ft_termcaps(void);
void						ft_cursor(char c);
void						setlist(t_line **list, char **str
							, int len);
char						*get_line(t_shell *shell);
int							autoimpl(char **str, t_shell *shell, int j);
int							ft_term(char **str, t_shell *shell, int j);
int							ft_init(struct termios *term);
void						insert_mode(char **str, int j, char c);
int							delete_mode(char **str, int j);
int							ft_config(struct termios *term);
int							ft_defconfig(struct termios *term);
int							print_promt(t_shell *shell, char *str, int j);

#endif
