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
// # include <X11/Xlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"

# define SCREEN_W 			670
# define SCREEN_H			480
# define N_COLORS			3*256
# define RANDR(lo,hi)		((lo) + (((hi)-(lo)) * drand48()))
# define random_bit()		random() & 01
# define NUMV				64
# define SAMPLES 			20000
# define ITT 				1000
# define SUPER 				1
# define GAMMA 				2.2
# define SEED 				1
# define ISBLACK(c)			(!c.r && !c.g && !c.b)
# define Aquamarine			rgb( 112, 219, 147)
# define MediumAquamarine	rgb(  50, 204, 153)
# define Black				rgb(   0,   0,   0)
# define Blue				rgb(   0,   0, 255)
# define CadetBlue			rgb(  95, 159, 159)
# define CornflowerBlue		rgb(  66,  66, 111)
# define DarkSlateBlue		rgb( 107,  35, 142)
# define LightBlue			rgb( 191, 216, 216)
# define LightSteelBlue		rgb( 143, 143, 188)
# define MediumBlue 		rgb(  50,  50, 204)
# define MediumSlateBlue	rgb( 127,   0, 255)
# define MidnightBlue		rgb(  47,  47,  79)
# define NavyBlue			rgb(  35,  35, 142)
# define Navy       rgb(  35,  35, 142)
# define SkyBlue    rgb(  50, 153, 204)
# define SlateBlue     rgb(0, 127, 255)
# define Coral					rgb(255 , 127, 0)
# define Cyan       rgb(   0, 255, 255)
# define SteelBlue     rgb( 35, 107, 142)
# define Firebrick     rgb( 142,  35,  35)
# define Gold       rgb( 204, 127,  50)
# define Goldenrod     rgb( 219, 219, 112)
# define MediumGoldenrod  rgb( 234, 234, 173)
# define Green      rgb(   0, 255,   0)
# define DarkGreen     rgb(  47,  79,  47)
# define DarkOliveGreen   rgb(  79,  79,  47)
# define ForestGreen   rgb(  35, 142,  35)
# define LimeGreen     rgb(  50, 204,  50)
# define MediumForestGreen   rgb( 107, 142,  35)
# define MediumSeaGreen   rgb(  66, 111,  66)
# define MediumSpringGreen   rgb( 127, 255,   0)
# define PaleGreen     rgb( 143, 188, 143)
# define SeaGreen      rgb(  35, 142, 107)
# define SpringGreen   rgb(   0, 255, 127)
# define YellowGreen   rgb( 153, 204,  50)
# define DarkSlateGrey    rgb(  47,  79,  79)
# define DimGrey    rgb(  84,  84,  84)
# define LightGrey     rgb( 168, 168, 168)
# define Khaki      rgb( 159, 159,  95)
# define Magenta    rgb( 255,   0, 255)
# define Maroon     rgb( 142,  35, 107)
# define Orange     rgb( 204,  50,  50)
# define Orchid     rgb( 219, 112, 219)
# define DarkOrchid    rgb( 153,  50, 204)
# define MediumOrchid     rgb( 147, 112, 219)
# define Pink       rgb( 188, 143, 143)
# define Plum       rgb( 234, 173, 234)
# define Red     rgb( 255,   0,   0)
# define IndianRed			  rgb( 79,  47,  47)
# define MediumVioletRed  rgb( 219, 112, 147)
# define OrangeRed     rgb( 255,   0, 127)
# define VioletRed     rgb( 204,  50, 153)
# define Salmon     rgb( 111,  66,  66)
# define Sienna     rgb( 142, 107,  35)
# define Tan     rgb( 219, 147, 112)
# define Thistle    rgb( 216, 191, 216)
# define Turquoise     rgb( 173, 234, 234)
# define DarkTurquoise    rgb( 112, 147, 219)
# define MediumTurquoise  rgb( 112, 219, 219)
# define Violet     rgb(  79,  47,  79)
# define BlueViolet    rgb( 159,  95, 159)
# define Wheat      rgb( 216, 216, 191)
# define White      rgb( 252, 252, 252)
# define Yellow     rgb( 255, 255,   0)
# define GreenYellow   rgb( 147, 219, 112)

typedef struct		s_rgb
{
	size_t			r;
	size_t			g;
	size_t			b;
}					t_rgb;

typedef struct	s_coord
{
	double			x;
	double			y;
	double			z;
}				t_coord;

typedef struct 		s_color
{
	double			ac;
	double			bc;
	double			cc;
	double			dc;
	double			ec;
	double			fc; /* set of coefficients a-f */
	double			pa1;
	double			pa2;
	double			pa3;
	double			pa4;
	t_rgb			rgb; /* color content of a pixel: RBG channels */
}					t_color; 

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

typedef union
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

typedef struct	s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data;
	int			sizel;
	int			endian;
	int			bpp;
	t_pixel		**pixels;	/* image buffer */
///
	int			yres; 		/* x and y resolution of image */
	int			xres;		/* x and y resolution of image */
	double		ranx;
	double		rany; 		/* numerical range of x/y axis */
	int			ncolors;	/* number of equations && colors */
	int 		sup;		/* super sample value  */
	int 		samples;	/* number of flame samples */
	long int 	max_i; 		/* number of iterations per sample */
	int 		invert;		/* use inverse colors? 0 false, else true */
	int 		symmetry;	/* use symmetrical rotation axis? set to greater than 1 */
	int 		seed;		/* random seed */
	double		gamma;		/* gamma correction factor */
	int 		(*funct)(struct s_env *env);		/* transformations to use */
	int 		count;		/* number of tranformations available */	
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom_x;
	double		zoom_y;
	
	t_color		*colormap;
	t_cplx		z;
	t_cplx		c;
	int 		conf;
}				t_env;

//mandel julia

t_cplx			conf(int i);
void			julia(t_env *env, int x, int y);
void			mendel(t_env *env, int x, int y);
void			linear(t_env *env, double x, double y);

int				main_mandel(t_env *env);
int 			main_flame(t_env *env);
int				pyramid(t_env *env);


//mlx init
void			init(t_env *env, char **av);
int				expose(t_env *env);
t_rgb			getpixel(t_env *env, int x, int y);
void			addpixel(t_env *env, int x, int y, t_rgb color);
void			plotpixel(t_env *env, int x, int y, t_rgb color);
//color

t_color			color();
t_rgb   		rgb(int x, int y, int z);
void			map(t_env *env);

#endif
