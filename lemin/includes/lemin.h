/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/13 08:42:21 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEMIN_H
# define	LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct 			s_lemroom
{
	int					dist;
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

t_lem					*parse();
t_lem					*newlem(void);
void					dellem(t_lem **lem);
t_lemroom				*allocroom(char *str);
t_lemroom				**alloctabroom(int i);
t_lemroom				*connect(t_lemroom *room, t_lem *lem);
void					delroom(t_lemroom **room);
t_lemroom				*newendroom(char *str);
void					deltabroom(t_lemroom ***room);
void					addroom(t_lemroom *room, char *str);
t_lemroom				**recupnextroom(t_lemroom **tabroom, t_lem *lem);
void					putroom(t_lemroom *room);
t_lemroom				**newtabroom(int i);
int						tabroomlen(t_lemroom **tabroom);
void					sort(t_lemroom **tabroom);
void					moove(t_lemroom **tab, int k);
void					epure(t_lemroom *room, t_lem *lem);
t_lemroom				**allconnect(t_lemroom **room, t_lem *lem);

#endif