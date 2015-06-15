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

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
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
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define KEYPRESS		2
# define KEYRELEASE		3
# define BUTTONPRESS	4
# define BUTTONRELEASE	5
# define MOTIONNOTIFY	6
# define KEYPRESSMASK	(1L<<0)
# define KEYRELEASEMASK	(1L<<1)
# define BUTTONPRESSMASK	(1L<<2)
# define BUTTONRELEASEMASK	(1L<<3)
# define POINTERMOTIONMASK	(1L<<6)

typedef struct			s_img
{
	void				*img;
	char				*data;
	int					sizel;
	int					endian;
	int					bpp;
}						t_img;

typedef	struct			s_env
{
	void				*ptr;
	void				*win;
	t_img				*img[11];
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	int					**worldmap;
	int					time;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					mapx;
	int					mapy;

	int					back;
	int					forward;
	int					left;
	int					right;

	double				wallx;
	int					texx;
	int					texy;
	int					texnum;

	double				floorxwall;
	double				floorywall;
	double				distwall;
	double				distplayer;
	double				currentdist;
	double				weight;
	double				currentfloorx;
	double				currentfloory;
	int					floortexx;
	int					floortexy;
}						t_env;

int						raycaster(t_env *env);
int						back(t_env *env, double movespeed);
int						forward(t_env *env, double movespeed);
int						turn_right(t_env *env, double rotspeed);
int						turn_left(t_env *env, double rotspeed);
int						key_hook(t_env *env);
int						key_release(int keycode, t_env *env);
int						key_press(int keycode, t_env *env);
int						get_map(int ***tab, char *file);
void					draw_floor(t_env *env, int x, int z);
int						wall(t_env *env);
void					draw_sky(t_env *env, int x, int z);
int						get_tex(t_env *env);
void					draw(t_env *env, int x);

#endif
