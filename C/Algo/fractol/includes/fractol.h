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
# define NCOLORS		3 * 10
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


#define KeyPressMask	(1L<<0)
#define KeyReleaseMask	(1L<<1)
#define Button3MotionMask	(1L<<10)
#define Button4MotionMask	(1L<<11)
#define Button5MotionMask	(1L<<12)
#define ButtonMotionMask	(1L<<13)
#define KeymapStateMask	(1L<<14)
#define ExposureMask	(1L<<15)
#define VisibilityChangeMask	(1L<<16)
#define StructureNotifyMask	(1L<<17)
#define ResizeRedirectMask	(1L<<18)
#define SubstructureNotifyMask	(1L<<19)
#define ButtonPressMask	(1L<<2)
#define SubstructureRedirectMask	(1L<<20)
#define FocusChangeMask	(1L<<21)
#define PropertyChangeMask	(1L<<22)
#define ColormapChangeMask	(1L<<23)
#define ButtonReleaseMask	(1L<<3)
#define EnterWindowMask	(1L<<4)
#define LeaveWindowMask	(1L<<5)
#define PointerMotionMask	(1L<<6)
#define PointerMotionHintMask	(1L<<7)
#define Button1MotionMask	(1L<<8)
#define Button2MotionMask	(1L<<9)

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
	int					sizel;
	int					endian;
	int					bpp;
	t_coeff				*coeff;
	t_rgb				rgbmap[3];
	t_rgb				pixels[SCREEN_W][SCREEN_H];
	t_cplx				*back;
	pthread_mutex_t		mutex;
	int					nc;
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	long double				ptx;
	long double				pty;
	int					yres;
	int					xres;
	double				ranx;
	double				rany;
	double				zoom_x;
	double				zoom_y;
	double				zoom_factor;
	long int 			max_i;
	void 				*(*fract)(void *arg);
	int 				count;	
	struct timeval		start;
	struct timeval		end;
	double 				conf;
	t_thread			*t;
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

void					init(t_env *env, char **av);
void					rgbmap(t_env *env);
t_coeff					*coeff(void);
void					cleanpixels(t_env *env);
void					imandel(t_env *env);
void					ijulia(t_env *env);
void					ibuddha(t_env *env);

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
