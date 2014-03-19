/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/17 12:17:10 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEMIN_H
# define	LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

/*
** Lists and Strutures
*/

typedef struct 			s_lemroom
{
	int					dist;
	int					step;
	int					lem;
	char				*name;
	struct s_lemroom	**tab;
}						t_lemroom;

typedef struct 			s_lem
{
	t_lemroom			*tab[1000];
	int					j;
	char				*start;
	char				*end;
}						t_lem;

/*
** Functions
*/

t_lem					*parse();
t_lem					*newlem(void);
void					lemin(t_lem *lem);
void					dellem(t_lem **lem);
t_lemroom				**newtabroom(int i);
t_lemroom				**alloctabroom(int i);
t_lemroom				*newendroom(char *str);
void					putroom(t_lemroom *room);
void					delroom(t_lemroom **room);
void					sort(t_lemroom **tabroom);
void					moove(t_lemroom **tab, int k);
void					deltabroom(t_lemroom ***room);
int						tabroomlen(t_lemroom **tabroom);
t_lemroom				*allocroom(char *str, t_lem *lem);
void					weight(t_lemroom *room, t_lem *lem);
void					connect(t_lemroom *room, t_lem *lem);
t_lemroom				**allconnect(t_lemroom **room, t_lem *lem);
void					addroom(t_lemroom *room, char *str, t_lem *lem);
t_lemroom				**recupnextroom(t_lemroom **tabroom, t_lem *lem);
t_lemroom				**merge(t_lemroom **tabroom, t_lemroom **tabroom1);

#endif/* !LEMIN_H */