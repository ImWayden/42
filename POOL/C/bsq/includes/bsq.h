/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 13:15:25 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 13:15:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					BSQ_H
# define				BSQ_H

# include <unistd.h>
# include <stdlib.h>

typedef struct			s_list
{
	int					i;
	int					j;
	struct s_list		*next;
}						t_list;

void					ft_putchar(char c);
void					ft_putnbr(int n);
void					ft_putstr(char *str);
void					ft_putendl(char *str);
t_list					*bsq(t_list *list, int i, int j, int c, char **tab);

#endif
