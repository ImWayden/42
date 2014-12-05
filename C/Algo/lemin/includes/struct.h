/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 18:37:15 by msarr             #+#    #+#             */
/*   Updated: 2014/12/04 18:37:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_room	t_room;

typedef struct		s_coord
{
	float			x;
	float			y;
	float			z;
}					t_coord;

typedef struct		s_link
{
	t_room			*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	int				x;
	int				y;
	int				z;
	int				dist;
	int				step;
	int				lem;
	char			*name;
	struct s_link	*lst;
}					t_room;

typedef	struct		s_env
{
	void			*ptr;
	void			*win;
	t_coord			**tab;
	t_room			**room;
	int				x;
	int				y;
	int				c;
	int				w;
	int				h;
	int				pad;
}					t_env;

typedef struct		s_lem
{
	t_room			*tab[1000];
	int				nbr;
	int				g;
	t_room			*start;
	t_room			*end;
}					t_lem;

typedef struct		s_trans
{
	char			*src;
	char			*dst;
	struct s_trans	*next;
}					t_trans;

#endif
