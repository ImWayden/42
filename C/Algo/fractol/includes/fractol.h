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
# include </usr/X11/include/X11/X.h>
//# include <X11/Xlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "colors.h"

# define SCREEN_W 			670
# define SCREEN_H			480
# define random_bit()		random() & 01
# define NCOLORS			3 * 10
# define SAMPLES 			20000
# define ITT 				1000
# define SUPER 				1
# define GAMMA 				2.2
# define SEED 				1
# define Divider			35
# define Power				1
# define Radius				1.332



typedef struct	s_coord
{
	double			x;
	double			y;
	double			z;
}				t_coord;


typedef struct		s_point
{
	t_coord			c;
	struct s_point	*next;
}					t_point;

typedef struct 		s_cplx
{
	double		r;
	double		i;
}					t_cplx;

typedef struct
{
	unsigned int counter; /* number of times pixel has been incremented */
	float normal; /* normalized value at pixel */
} 					hitcounter;

typedef struct		t_pixel
{
	hitcounter		value; 
	unsigned char	r; /* color content of a pixel: rgb channels */
	unsigned char	g; /* color content of a pixel: rgb channels */
	unsigned char	b; /* color content of a pixel: rgb channels */
}					t_pixel;

typedef struct		s_triangle
{
	t_coord			p1;
	t_coord			p2;
	t_coord			p3;
}					t_triangle;

typedef struct		s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data;
	int			sizel;
	int			endian;
	int			bpp;

	t_pixel		**pixels;	/* image buffer */
	t_color		*colormap;
	t_rgb		rgbmap[3];
	t_hsl		hslmap[3];
	int			ncolors;	/* number of equations && colors */

///
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			yres; 		/* x and y resolution of image */
	int			xres;		/* x and y resolution of image */
	double		ranx;
	double		rany; 		/* numerical range of x/y axis */
	double		zoom_x;
	double		zoom_y;

	long int 	max_i; 		/* number of iterations per sample */
	int 		invert;		/* use inverse colors? 0 false, else true */
	int 		symmetry;		/* use inverse colors? 0 false, else true */
	int 		samples;		/* use inverse colors? 0 false, else true */
	int 		(*funct)(struct s_env *env);		/* transformations to use */
	int 		count;		/* number of tranformations available */	
	
	t_cplx		z;
	t_cplx		c;
	double		dist;
	double		p;
	int 		conf;
}				t_env;

//mandel julia

double			dot(t_cplx a, t_cplx b);
t_cplx			conf(int i);
void			julia(t_env *env, int x, int y);
void			mendel(t_env *env, int x, int y);
void			linear(t_env *env, double x, double y);

int				main_mandel(t_env *env);
int 			main_flame(t_env *env);
int				main_attract(t_env *env);


//mlx init
void			init(t_env *env, char **av);
void			intervals(t_env *env, char **av, int i);
int				expose(t_env *env);
t_rgb			getpixel(t_env *env, int x, int y);
void			plot3d(t_env *env, t_coord c, int i);
t_coord			coord(double x, double y, double z);
t_rgb			orbittrap(t_env *env);
t_rgb			style1(t_env *env, t_rgb color);
t_rgb			style2(t_env *env, t_rgb color, int i);
void			addpixel(t_env *env, int x, int y, t_rgb color);
void			plotpixel(t_env *env, int x, int y, t_rgb color);
void			pixelmap(t_env *env);
void			colormap(t_env *env);


#endif
