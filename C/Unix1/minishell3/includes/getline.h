/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:00:45 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 23:03:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include "libft.h"
# include "minishell2.h"


typedef struct termios		t_termios;

void						ft_termcaps(void);
void						ft_cursor(char c);
char						*get_line(t_shell *shell);
int							ft_term(t_shell *shell, char **str);
int							ft_init(struct termios *term);
int							ft_config(struct termios *term);
int							ft_defconfig(struct termios *term);


#endif
