/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:29:31 by msarr             #+#    #+#             */
/*   Updated: 2014/03/09 01:50:58 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			P4_H
# define		P4_H

#include		"../libft/includes/libft.h"
#include		"../libft/includes/get_next_line.h"

typedef struct 		s_gameroom
{
	int				*cord;
	char			**tab;
}					t_gameroom;

typedef struct 		s_gamemem
{
	int				p[2];
	int				p1[2];
}					t_gamemem;

typedef struct 		s_playmem
{
	int				mdle;
	int				**tab;
}					t_playmem;

t_gamemem			*new();
t_gamemem			*add(t_gamemem *mem, int i, int j);
int					isnbr(char *str);
void				game(char	**argv);
void				printroom(char **str);
t_gameroom			*firstread(char **argv);
t_gameroom			*newgameroom(int tab[2]);
void				player(t_gameroom *game);
int					verif(int i, t_gameroom *game);
int					checkobl(t_gameroom *game, char c);
int					checkiobl(t_gameroom *game, char c);
int					checkvert(t_gameroom *game, char c);
int					checkhor(t_gameroom *game, char c);
int					while2(t_gameroom *game, char c, int i, int j);
int					while1(t_gameroom *game, char c, int i, int j);
void				insert(t_gameroom *game, int i, int player);

#endif
