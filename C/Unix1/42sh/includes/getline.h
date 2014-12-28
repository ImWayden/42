/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:00:45 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 00:28:28 by msarr            ###   ########.fr       */
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
# include <signal.h>
# include "struct.h"
# include "libft.h"
# include "define.h"

typedef struct termios		t_termios;

void						ft_termcaps(void);
void						ft_cursor(char c);
void						setlist(t_line **list, char **str, int len);
char						*get_line(t_shell *shell, int i);
int							autoimpl(char **str, t_shell *shell, int j);
char						*ft_term(t_shell *shell, int j, int f);
int							ft_init(struct termios *term);
void						insert_mode(char **str, int j, char c, char *buf);
int							delete_mode(char **str, int j, char *buf);
int							ft_config(struct termios *term);
int							ft_defconfig(struct termios *term);
int							print(char *str, int j, char *buf);
void						term_center(t_shell *shell, char **str, char *buf
							, int *j);
int							editing(char *str, int j, int len);

#endif
