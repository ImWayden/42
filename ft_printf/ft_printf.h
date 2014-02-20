/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 11:27:36 by msarr             #+#    #+#             */
/*   Updated: 2013/12/17 11:27:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct 		s_list
{
	char			name;
	char			option[10];
	int				i;
	struct s_list	*next;
}					t_list;

t_list		*ft_add_list(t_list *list, char *str, int i);
int			ft_search(char	*str);
int			ft_printf(char *str, ...);
t_list		*ft_recup(char *str);
int			ft_put(t_list *list, char *str, ...);
int			ft_isoption(char *str, t_list *list);
void		ft_verif(char **str , t_list **list);
char		*ft_strreverse(const char *s);
char		*ft_itoa(int n);
void		ft_putstr(const char *str);
char		*ft_strnew(size_t size);
int			ft_isalpha(int c);
int			ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_octal(long n);
void		ft_putnbr(int n);
void		ft_putchar(char c);
char		*ft_hexa(size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif /* !FT_PRINTF_H */
