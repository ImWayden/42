/* ************************************************************************** */
/*                   */
/*              :::   ::::::::   */
/*   fractol.h            :+:   :+: :+:   */
/*             +:+ +:+   +:+  */
/*   By: msarr <msarr@student.42.fr>    +#+  +:+    +#+  */
/*            +#+#+#+#+#+   +#+     */
/*   Created: 2015/01/20 14:05:30 by msarr    #+# #+#    */
/*   Updated: 2015/01/20 14:05:30 by msarr   ###   ########.fr    */
/*                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
//# include <X11/Xlib.h>
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
# define SAMPLES 		20000
# define ITT 			1000
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

typedef struct			s_env t_env;

typedef struct			s_thread
{
	int					y_min;
	int					y_max;
	pthread_t			thread;
	t_env				*env;
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

typedef struct
{
	unsigned int 		counter; /* number of times pixel has been incremented */
	float 				normal; /* normalized value at pixel */
} 						hitcounter;

typedef struct			t_pixel
{
	hitcounter			value; 
	t_rgb				rgb;
}						t_pixel;

typedef struct			s_triangle
{
	t_coord				p1;
	t_coord				p2;
	t_coord				p3;
}						t_triangle;

typedef struct			s_var
{
	double				d1;
	double				d2;
	double				d3;
	double				d4;
}						t_var;

typedef struct			s_env
{
	void				*ptr;
	void				*win;
	void				*img;
	char				*data;
	int					sizel;
	int					endian;
	int					bpp;

	int					left;
	int					right;

	t_pixel				**pixels;
	t_color				*colormap;
	t_rgb				rgbmap[3];
	t_hsl				hslmap[3];
	int					ncolors;


	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	double				ptx;
	double				pty;
	int					yres;
	int					xres;
	double				ranx;
	double				rany;
	double				zoom_x;
	double				zoom_y;
	double				zoom_factor;
	t_thread			threadtab[100];

	long int 			max_i;
	long int 			i;
	int 				invert;
	int 				symmetry;
	int 				samples;
	void 				*(*main)(void *arg);
	int 				count;	
	
	struct timeval		start;
	struct timeval		end;

	t_cplx				z;
	t_cplx				c;
	double				dist;
	double				p;
	double 				conf;
}						t_env;


/*
** Mandelbrot
*/

t_cplx					conf(double i);
void					*mandelbrot(void *env);
void					*flame(void *env);
t_rgb					julia_iter(t_env *env, int x, int y);
t_rgb					mandel_iter(t_env *env, int x, int y);
int						main_attract(t_env *env);

/*
** Flames
*/

t_cplx					linear(t_color col, double x, double y);
t_cplx					sinusoidal(t_color col, double x, double y);
t_cplx					spherical(t_color col, double x, double y);
t_cplx					swirl(t_color col, double x, double y);
t_cplx					horseshoe(t_color col, double x, double y);
t_cplx					polar(t_color col, double x, double y);
t_cplx					handker(t_color col, double x, double y);
t_cplx					heart(t_color col, double x, double y);
t_cplx					disk(t_color col, double x, double y);
t_cplx					spiral(t_color col, double x, double y);
t_cplx					hyper(t_color col, double x, double y);
t_cplx					diamond(t_color col, double x, double y);
t_cplx					f_exp(t_color col, double x, double y);
t_cplx					f_julia(t_color col, double x, double y);
t_cplx					bent(t_color col, double x, double y);
t_cplx					waves(t_color col, double x, double y);
t_cplx					fisheye(t_color col, double x, double y);
t_cplx					popcorn(t_color col, double x, double y);
t_cplx					exponential(t_color col, double x, double y);
t_cplx					power(t_color col, double x, double y);
t_cplx					cosine(t_color col, double x, double y);
t_cplx					rings(t_color col, double x, double y);
t_cplx					fan(t_color col, double x, double y);
t_cplx					blob(t_color col, double x, double y);
t_cplx					pdj(t_color col, double x, double y);
t_cplx					fan2(t_color col, double x, double y);
t_cplx					rings2(t_color col, double x, double y);
t_cplx					eyefish(t_color col, double x, double y);
t_cplx					bubble(t_color col, double x, double y);
t_cplx					cylinder(t_color col, double x, double y);
t_cplx					noise(t_color col, double x, double y);
t_cplx					blur(t_color col, double x, double y);
t_cplx					curl(t_color col, double x, double y);
t_cplx					tangent(t_color col, double x, double y);
t_cplx					square(t_color col, double x, double y);
t_cplx					cross(t_color col, double x, double y);
t_cplx					collatz(t_color col, double x, double y);
t_cplx					mobius(t_color col, double x, double y);
t_cplx					bwaves(t_color col, double x, double y);

/*
** Prog Init
*/

void					init(t_env *env, char **av);
void					mandel_init(t_env *env);
void					julia_init(t_env *env);
void					flame_init(t_env *env, char *av);

/*
** Pixels && Colors
*/

t_rgb					getpixel(t_env *env, int x, int y);
void					plot3d(t_env *env, t_coord c, int i);
t_coord					coord(double x, double y, double z);
void					addpixel(t_env *env, int x, int y, t_rgb color);
void					plotpixel(t_env *env, int x, int y, t_rgb color);
void					pixelmap(t_env *env);
void					colormap(t_env *env);

/*
** Background
*/

t_rgb					orbittrap(t_env *env);
t_rgb					lerp(t_cplx z, double t);
t_rgb					style1(t_env *env, t_rgb color);
t_rgb					basecolor(t_cplx z);
t_rgb					style2(t_env *env, t_rgb color, int i);
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
