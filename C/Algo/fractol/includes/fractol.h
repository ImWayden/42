/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:18:22 by msarr             #+#    #+#             */
/*   Updated: 2015/03/07 14:18:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include "libft.h"
# include "colors.h"
# include "complex.h"

# define SCREEN_W 		670
# define SCREEN_H		480
# define random_bit()	random() & 01
# define NCOLORS		3
# define NCOEFF			30
# define ZOOM_FACTOR	1.1
# define SAMPLES 		2000
# define ITT 			10000
# define SUPER 			1
# define GAMMA 			2.2
# define SEED 			1
# define Divider		35
# define Power			1
# define Radius			1.332
# define RANDR(lo,hi)	((lo) + (((hi)-(lo)) * drand48()))
# define MIN(a, b)		((a < b) ? a : b)
# define MAX(a, b)		((a > b) ? a : b)
# define MAX3(a, b, c)	MAX(a, MAX(b, c))
# define MIN3(a, b, c)	MIN(a, MIN(b, c))
# define MAX_R			1000
# define MAX_G			200
# define MAX_B			20
# define ButtonPress	4
# define ButtonRelease	5
# define MotionNotify	6
# define KeyPressMask	(1L<<0)
# define KeyReleaseMask	(1L<<1)
# define ButtonPressMask	(1L<<2)
# define ButtonReleaseMask	(1L<<3)
# define PointerMotionMask	(1L<<6)


typedef struct			s_env t_env;

typedef struct			s_thread
{
	int					y;
	int					x;
	char				*pix;
	t_env				*env;
	pthread_t			t;
}						t_thread;

typedef struct			s_coord
{
	double				x;
	double				y;
	double				z;
}						t_coord;


typedef struct			s_point
{
	t_coord				c;
	struct s_point		*next;
}						t_point;

typedef struct 				s_coeff
{
	double					ac;
	double					bc;
	double					cc;
	double					dc;
	double					ec;
	double					fc;
	double					pa1;
	double					pa2;
	double					pa3;
	double					pa4;
}							t_coeff; 

typedef struct			s_triangle
{
	t_coord				p1;
	t_coord				p2;
	t_coord				p3;
}						t_triangle;

typedef struct			s_env
{
	void				*ptr;
	void				*win;
	void				*img;
	char				*data;
	t_coeff				*coeff;
	t_rgb				*color;
	t_rgb				*pixel;
	double				zoom;
	long double			ptx;
	long double			pty;
	long int 			max_i;
	struct timeval		start;
	struct timeval		end;
	t_thread			*t;
	void 				*(*fract)(void *arg);
}						t_env;


/*
** Mandelbrot
*/

t_cplx					conf(double i);
int						render(t_env *env);
void					*julia(void *arg);
void					*mandel(void *arg);
void					*buddha(void *arg);
int						main_attract(t_env *env);
void					getarg(void *arg, t_env **env, int *x, int *y);

/*
** Flames
*/

t_cplx					linear(t_coeff col, double x, double y);
t_cplx					sinusoidal(t_coeff col, double x, double y);
t_cplx					spherical(t_coeff col, double x, double y);
t_cplx					swirl(t_coeff col, double x, double y);
t_cplx					horseshoe(t_coeff col, double x, double y);
t_cplx					polar(t_coeff col, double x, double y);
t_cplx					handker(t_coeff col, double x, double y);
t_cplx					heart(t_coeff col, double x, double y);
t_cplx					disk(t_coeff col, double x, double y);
t_cplx					spiral(t_coeff col, double x, double y);
t_cplx					hyper(t_coeff col, double x, double y);
t_cplx					diamond(t_coeff col, double x, double y);
t_cplx					f_exp(t_coeff col, double x, double y);
t_cplx					f_julia(t_coeff col, double x, double y);
t_cplx					bent(t_coeff col, double x, double y);
t_cplx					waves(t_coeff col, double x, double y);
t_cplx					fisheye(t_coeff col, double x, double y);
t_cplx					popcorn(t_coeff col, double x, double y);
t_cplx					exponential(t_coeff col, double x, double y);
t_cplx					power(t_coeff col, double x, double y);
t_cplx					cosine(t_coeff col, double x, double y);
t_cplx					rings(t_coeff col, double x, double y);
t_cplx					fan(t_coeff col, double x, double y);
t_cplx					blob(t_coeff col, double x, double y);
t_cplx					pdj(t_coeff col, double x, double y);
t_cplx					fan2(t_coeff col, double x, double y);
t_cplx					rings2(t_coeff col, double x, double y);
t_cplx					eyefish(t_coeff col, double x, double y);
t_cplx					bubble(t_coeff col, double x, double y);
t_cplx					cylinder(t_coeff col, double x, double y);
t_cplx					noise(t_coeff col, double x, double y);
t_cplx					blur(t_coeff col, double x, double y);
t_cplx					curl(t_coeff col, double x, double y);
t_cplx					tangent(t_coeff col, double x, double y);
t_cplx					square(t_coeff col, double x, double y);
t_cplx					cross(t_coeff col, double x, double y);
t_cplx					collatz(t_coeff col, double x, double y);
t_cplx					mobius(t_coeff col, double x, double y);
t_cplx					bwaves(t_coeff col, double x, double y);

/*
** Prog Init
*/

t_rgb					*rgbmap(void);
t_coeff					*coeffmap(void);
t_rgb					*pixelmap(void);
t_thread				*threadmap(t_env *env);
void					ft_exit(t_env *env, char *str);
void					init(t_env *env, char **av, int ac);

/*
** Colors
*/

void					plot3d(t_env *env, t_coord c, int i);
t_coord					coord(double x, double y, double z);
void					lotpixel(char *data, t_rgb color);
void					addpixel(t_env *env, int x, int y, t_rgb color);
void					plotpixel(t_env *env, int x, int y, t_rgb color);
t_rgb					getpixel(t_env *env, int x, int y);
t_rgb					getcolor(t_cplx z);
void					putpixels(t_env *env);

/*
** Background
*/

t_rgb					orbittrap(t_env *env, t_cplx z);
t_rgb					lerp(t_cplx z, double t);
t_rgb					style1(t_cplx z, t_rgb color);
t_rgb					basecolor(t_cplx z, t_rgb color);
t_rgb					style2(t_cplx z, t_rgb color, int i);
double					clamp(double value, double min, double max);

/*
** MLX
*/

void					zoom(t_env *env);
int						expose(t_env *env);
int						loop_hook(t_env *env);
int						mouse_press(int button, int x, int y, t_env *env);
int						key_hook(int keycode, t_env *env);
int						mouse_motion(int x, int y, t_env *env);

#endif
