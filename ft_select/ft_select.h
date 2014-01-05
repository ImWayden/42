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

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>

typedef struct 		s_list
{
	char			*str;
	int 			curseur;
	int 			select;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int		ft_effect(t_list *list);
int		ft_effect2(t_list *list);
int		ft_init(struct termios *term);
int		ft_config(struct termios *term);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	ft_putstr(char *str);
void	ft_putlist(t_list *list);
int		ft_recup(char **str, t_list **list);
t_list		*ft_addlist(t_list *list, char *str);
int		ft_defconfig(struct termios *term);
t_list	*ft_add_list(t_list *list, char *str);

#endif