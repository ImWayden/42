/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/02 03:51:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <errno.h>
# include <stdio.h>
# include "libft.h"

/*
** Lists and Strutures
*/

typedef struct		s_room  t_room;

typedef struct		s_link
{
	t_room			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	int				dist;
	int				step;
	int				lem;
	char			*name;
	struct s_link	*lst;
}					t_room;

typedef struct		s_lem
{
	t_room			*tab[1000];
	int				nbr;
	t_room			*start;
	t_room			*end;
}					t_lem;

/*
** Functions
*/

t_lem				*parse();
t_lem				*newlem(void);
t_room				*new_room(char *str);
int					get_door(t_lem *lem, int flag);
t_link				*new_link(t_room *room);
int					way(t_room *room, t_lem *lem);
int					add_link(char *str, t_lem *lem);
int					hash(char *str);
void				lemin(t_lem *lem);
int					get_room(char *str, t_lem *lem, int flag);


#endif