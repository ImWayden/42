/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:41:52 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 17:34:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include </usr/X11/include/X11/X.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_env	t_env;

typedef struct		s_obj
{
	int				w;
	int				h;
	void			*img;
	char			*data;
	char			*word;
	int				sizel;
	int				endian;
	int				bpp;
	int				(*f)(t_env *);
}					t_obj;

typedef struct		s_win
{
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
	t_obj			*obj;
}					t_win;

typedef	struct		s_env
{
	void			*ptr;
	void			*win;
	t_win			subwin[3];
}					t_env;

t_win				window(int x_min, int x_max, int y_min, int y_max);
void				plot_win(t_env *env, t_win win)
#endif
