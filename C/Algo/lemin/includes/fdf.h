/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/12/03 22:51:35 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "lemin.h"

# define	COLOR_BLACK		0x000000
# define	COLOR_WHITE		0xFFFFFF
# define	COLOR_RED 		0xFF0000
# define	COLOR_GREEN		0x00FF00
# define	COLOR_BLUE  	0x0000FF
# define	COLOR_ORANGE 	0xD27701
# define	COLOR_YELLOW  	0xDDBA01

# define	COLOR2_RED    	0xC00F12
# define	COLOR2_GREEN 	0x007A28
# define	COLOR2_BLUE   	0x3B9B95

# define SQUARE(x) ((x)*(x))

typedef struct	s_coord
{
	float			x;
	float			y;
	float			z;
}				t_coord;

typedef	struct	s_env
{
	void		*ptr;
	void		*win;
	t_coord		**tab;
	t_room		**room;
	int			x;
	int			y;
	int			c;
	int			w;
	int			h;
	int			pad;
}				t_env;

t_coord			new_coord(float x, float y);
int				fake_expose(t_env *envc);
int				fdf(t_env env);
void			drawline(t_env env, t_coord p, t_coord p1);
void			project(t_env *env, t_room **room);
void		draw_lem(t_env *env, t_room **room);

#endif
