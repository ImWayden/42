/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/04 16:55:04 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEMIN_H
# define	LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct 			s_lemlist
{
	char				*str;
	struct s_lemlist	*next;
}						t_lemlist;

typedef struct 			s_lem
{
	t_lemlist			*tab[1000];
	int					j;
	char				*start;
	char				*end;
}						t_lem;

int					hashcode(char *str);
t_lem				*parse();
t_lemlist			*ft_lemlistnew(char *str);
t_lemlist			*ft_addlemlist(t_lemlist *list, char *str);

#endif