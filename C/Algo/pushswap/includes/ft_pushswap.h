/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:18:41 by msarr             #+#    #+#             */
/*   Updated: 2013/12/24 15:18:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct			s_lex
{
	int					flag;
	int					name;
	int					nbr;
	struct s_lex		*next;
	struct s_lex		*prev;
}						t_lex;

void	dell_list(t_lex **lex);
int		get_flag(t_lex *lex);
void	ft_putlist(t_lex *list);
t_lex	*ft_get(char **str, int flag);
int		ft_s(t_lex *list);
void	ft_p(t_lex **list1, t_lex **list2, char c);
void	ft_ss(t_lex *lista, t_lex *listb);
int		ft_rr(t_lex **list);
int		ft_r(t_lex **list);
void	ft_r_r(t_lex **lista, t_lex **listb);
void	ft_rrr(t_lex **lista, t_lex **listb);
void	ft_sortlist(t_lex **list);;
int		ft_sortb(t_lex **l_a, t_lex **l_b, int (*f)(int, int), int (*f1)(int, int));
int		ft_sort(t_lex **l_a, t_lex **l_b, int (*f)(int, int), int (*f1)(int, int));
void	ft_debug(t_lex *l_a, t_lex *l_b);
int		ft_issort(t_lex *lex, int (*f)(int, int));

#endif

