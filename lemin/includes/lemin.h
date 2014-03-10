/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/08 01:27:36 by mozzie           ###   ########.fr       */
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

t_lem					*parse();
t_lem					*newlem(void);
t_lemlist				*ft_lemlistnew(char *str);
t_lemlist				*is(t_lemlist *list, t_lem *lem);
t_lemroom				*newroom(char *str, t_lem *lem);
t_lemlist				*ft_addlemlist(t_lemlist *list, char *str);
int						ft_lemlistlen(t_lemlist *list, char * str1, char *str2);
t_lemroom				**recupnextroom(t_lemroom **tabroom, t_lem *lem);
void					putroom(t_lemroom *room);
void					weight(t_lemroom *room, t_lem *lem);
t_lemroom				**newtabroom(int i);
int						tabroomlen(t_lemroom **tabroom);
t_lemroom				**merge(t_lemroom **tabroom, t_lemroom **tabroom1);
void					sort(t_lemroom **tabroom);
void					delroomlist(t_lemroom *room, t_lem *lem);
void					tabroomcpy(t_lemroom **tab, t_lemroom **tab1, t_lemroom **tab2);

#endif