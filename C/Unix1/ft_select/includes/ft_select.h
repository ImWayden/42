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

#ifndef 					FTSELECT_H
# define 					FTSELECT_H

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

typedef struct				s_select
{
	char					*str;
	int 					curseur;
	int 					select;
	int 					row;
	int 					col;
	int 					pos;
	struct s_select			*next;
	struct s_select			*prev;
}							t_select;

typedef struct				s_bar
{
	t_select				*list;
	int						argc;
}							t_bar;

int							ft_effect(t_select **list, int argc);
int							ft_effect2(t_select *list);
int							ft_init(struct termios *term);
int							ft_config(struct termios *term);
void						ft_sendlist(t_select *list);
t_select					*ft_setlist(t_select *list, int argc);
int							ft_recup(char **str, t_select **list);
t_select					*ft_addlist(t_select *list, char *str, int pos);
int							ft_defconfig(struct termios *term);
t_select					*ft_add_list(t_select *list, char *str);
void						ft_dellistelmt(t_select **list);
t_select					*ft_listnew(char *str, int pos);

#endif
