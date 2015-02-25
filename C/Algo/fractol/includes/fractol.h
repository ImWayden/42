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
# define MIN(a, b)		a < b ? a : b
# define MAX(a, b)		a > b ? a : b
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
	void 				*(*funct)(void *arg);
	int 				count;	
	
	struct timeval		start;
	struct timeval		end;

	t_cplx				z;
	t_cplx				c;
	double				dist;
	double				p;
	int 				conf;
}						t_env;


/*
** Mandelbrot
*/

t_cplx					conf(int i);
void					*mandelbrot(void *env);
void					*flame(void *env);
t_rgb					julia_iter(t_env *env, int x, int y);
t_rgb					mandel_iter(t_env *env, int x, int y);
int						main_attract(t_env *env);

/*
** Flames
*/

t_cplx					linear(t_env *env, double x, double y, int i);
t_cplx					sinusoidal(t_env *env, double x, double y, int i);
t_cplx					spherical(t_env *env, double x, double y, int i);
t_cplx					swirl(t_env *env, double x, double y, int i);
t_cplx					horseshoe(t_env *env, double x, double y, int i);
t_cplx					polar(t_env *env, double x, double y, int i);
t_cplx					handker(t_env *env, double x, double y, int i);
t_cplx					heart(t_env *env, double x, double y, int i);
t_cplx					disk(t_env *env, double x, double y, int i);
t_cplx					spiral(t_env *env, double x, double y, int i);
t_cplx					hyper(t_env *env, double x, double y, int i);
t_cplx					diamond(t_env *env, double x, double y, int i);
t_cplx					f_exp(t_env *env, double x, double y, int i);
t_cplx					f_julia(t_env *env, double x, double y, int i);
t_cplx					bent(t_env *env, double x, double y, int i);
t_cplx					waves(t_env *env, double x, double y, int i);
t_cplx					fisheye(t_env *env, double x, double y, int i);
t_cplx					popcorn(t_env *env, double x, double y, int i);
t_cplx					exponential(t_env *env, double x, double y, int i);
t_cplx					power(t_env *env, double x, double y, int i);
t_cplx					cosine(t_env *env, double x, double y, int i);
t_cplx					rings(t_env *env, double x, double y, int i);
t_cplx					fan(t_env *env, double x, double y, int i);
t_cplx					blob(t_env *env, double x, double y, int i);
t_cplx					pdj(t_env *env, double x, double y, int i);
t_cplx					fan2(t_env *env, double x, double y, int i);
t_cplx					rings2(t_env *eenv, double x, double y, int i);
t_cplx					eyefish(t_env *env, double x, double y, int i);
t_cplx					bubble(t_env *env, double x, double y, int i);
t_cplx					cylinder(t_env *env, double x, double y, int i);
t_cplx					noise(t_env *env, double x, double y, int i);
t_cplx					blur(t_env *env, double x, double y, int i);
t_cplx					curl(t_env *env, double x, double y, int i);
t_cplx					tangent(t_env *env, double x, double y, int i);
t_cplx					square(t_env *env, double x, double y, int i);
t_cplx					cross(t_env *env, double x, double y, int i);
t_cplx					collatz(t_env *env, double x, double y, int i);
t_cplx					mobius(t_env *env, double x, double y, int i);
t_cplx					bwaves(t_env *env, double x, double y, int i);

/*
** Prog Init
*/

void					init(t_env *env, char **av);
void					intervals(t_env *env, char **av, int i);

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
t_rgb					lerp(t_env *env, double t);
t_rgb					style1(t_env *env, t_rgb color);
t_rgb					basecolor(t_env *env);
t_rgb					style2(t_env *env, t_rgb color, int i);
double					clamp(double value, double min, double max);

/*
** MLX
*/

int						expose(t_env *env);
int						loop_hook(t_env *env);
int						mouse_press(int button, int x, int y, t_env *env);
int						mouse_motion(int x, int y, t_env *env);

#endif
