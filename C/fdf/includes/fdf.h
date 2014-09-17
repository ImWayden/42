/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:09:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/27 22:31:35 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PADDING 30

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

/*
** Lists and Structures
*/

typedef	struct	s_env
{
	void		*ptr;
	void		*win;
	int			nbr_line;
	int			nbr_col;
	int			fd;
	char		*line;
	int			*tab;
	int			count;
	int			width1;
	int			height1;
	int			width2;
	int			height2;
	int			width3;
	int			height3;
	int			i;
	int			j;
	int			k;
}				t_env;

/*
** Protos
*/

void			fake_expose(t_env env);
int				ft_key_hook(int keycode);
int				ft_mouse_hook(int button, int x, int y);
void			ft_put_line(int w1, int h1, int w2, int h2, t_env env);
void			ft_put_line2(int w1, int h1, int w2, int h2, t_env env);
void			ft_nbr_line_col(char *str, t_env *env);

#endif
