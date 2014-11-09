/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:41:52 by msarr             #+#    #+#             */
/*   Updated: 2014/11/09 02:32:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include </usr/X11/include/X11/X.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

# define WHITE_2	 	0xFFFFF0
# define RED_2			0xCC0000
# define GREEN_2		0x00CC00
# define YELLOW_2    	0xCCFF00
# define BLUE_2      	0x000066
# define PURPLE_2   	0x330000
# define CYAN_2      	0x00FFFF
# define GREY_2			0x808080
# define SCREENWIDTH 	512
# define SCREENHEIGHT	384
# define MAPWIDTH		24
# define MAPHEIGHT 		24
# define UP				65362
# define DOWN			65364
# define LEFT			65361
# define RIGHT			65363

typedef struct s_img
{
	void		*img;
	char		*data;
	int			sizel;
	int			endian;
	int			bpp;
}				t_img;

typedef	struct	s_env
{
	void		*ptr;
	void		*win;
	t_img		*img[11];
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			**worldmap;
	int			time;
	int			oldTime;
	double		camerax;    
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			mapx;
	int			mapy;

	int			back;
	int			forward;
	int			left;
	int			right;

	double		wallx;
	int			texx;
	int			texy;
	int 		texnum;

	double		floorxwall;
	double		floorywall;
	double		distwall;
	double		distplayer;
	double		currentdist;
	double		weight;
	double 		currentfloorx;
	double 		currentfloory;
	int 		floortexx;
	int 		floortexy;
}				t_env;

int					raycaster(t_env *env);
int					back(t_env *env, double moveSpeed);
int					forward(t_env *env, double moveSpeed);
int 				turn_right(t_env *env, double rotSpeed);
int 				turn_left(t_env *env, double rotSpeed);
int					ft_key_hook(t_env *env);
int					ft_key_release(int keycode, t_env *env);
int					ft_key_press(int keycode, t_env *env);
int					get_map(int ***tab, char *file);
void				drawing_floor(t_env *env, int x, int z);
void				drawing_sky(t_env *env, int x, int z);
int 				ft_get_tex(t_env *env);
void				draw(t_env *env, int x);

#endif
