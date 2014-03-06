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
	t_lemlist			*list;
	t_lemlist			*tab[1000];
	int					j;
	char				*start;
	char				*end;
}						t_lem;

typedef struct 			s_lemroom
{
	int					dist;
	char				*name;
	struct s_lemroom	**tab;
}						t_lemroom;

int						hashcode(char *str);
t_lem					*parse();
t_lemlist				*ft_lemlistnew(char *str);
t_lemroom				*newroom(char *str);
t_lemlist				*ft_addlemlist(t_lemlist *list, char *str);
int						ft_lemlistlen(t_lemlist *list);
void					recupnextroom(t_lemroom *room, t_lem *lem);
t_lemroom				*recupallroom(t_lemroom *room, t_lem *lem);

#endif