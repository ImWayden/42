/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ord_alphlong.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 16:49:06 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 17:53:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ORD_ALPHLONG_H
# define	ORD_ALPHLONG_H

typedef struct 		s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

int     ft_strcmp(char *s1, char *s2);
char    *ft_recupwords(char **str);
int     ft_strlen(char *s1);

#endif
