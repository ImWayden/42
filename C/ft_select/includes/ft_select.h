/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:00:45 by msarr             #+#    #+#             */
/*   Updated: 2014/01/03 15:00:48 by msarr            ###   ########.fr       */
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
# include <term.h>
# include "libft.h"

typedef struct				s_selectlist
{
	char					*str;
	int 					curseur;
	int 					select;
	int 					row;
	int 					col;
	struct s_selectlist		*next;
	struct s_selectlist		*prev;
}							t_selectlist;

typedef struct				s_bar
{
	t_selectlist			*list;
}							t_bar;

int							ft_effect(t_selectlist **list);
int							ft_selectlistlen(t_selectlist *list);;
int							ft_effect2(t_selectlist *list);
int							ft_init(struct termios *term);
int							ft_config(struct termios *term);
void						ft_putlist(t_selectlist *list);
void						ft_sendlist(t_selectlist *list);
t_selectlist				*ft_setlist(t_selectlist *list);
int							ft_recup(char **str, t_selectlist **list);
t_selectlist				*ft_addlist(t_selectlist *list, char *str);
int							ft_defconfig(struct termios *term);
t_selectlist				*ft_add_list(t_selectlist *list, char *str);
t_selectlist				*ft_dellistelmt(t_selectlist **list, char *str);
t_selectlist				*ft_listnew(char *str);

#endif
