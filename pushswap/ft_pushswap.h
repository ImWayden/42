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

#ifndef			FT_PUSHSWAP_H
# define		FT_PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>


typedef struct		s_list
{
	int		i;
	struct s_list *next;
}					t_list;

void		ft_putlist(t_list *list);
t_list		*ft_recup(char **str, int i);
void		ft_p(t_list **list, t_list	**list1);
void		ft_s(t_list *list);
void		ft_r(t_list *list);
void		ft_rr(t_list **list);
t_list		*ft_sortlist(t_list **lista);
int			ft_listlen(t_list *list);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
t_list		*ft_addlist(t_list *list, int i);
void		ft_putnbr(int n);
void		ft_putchar(char c);
int			ft_lislen(t_list *list);
t_list		*ft_merge(t_list **lista, t_list **listb);
t_list		*ft_pushswap(t_list **lista);
int			ft_issort(t_list *list);

#endif

