/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 23:02:56 by msarr             #+#    #+#             */
/*   Updated: 2015/02/01 23:02:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdlib.h>

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

# define RANDR(lo,hi)		((lo) + (((hi)-(lo)) * drand48()))
# define	MIN(a,b) (((a)<(b))?(a):(b))
# define	MAX(a,b) (((a)>(b))?(a):(b))
# define	MAX3(a,b,c) MAX(a,MAX(b,c))
# define	MIN3(a,b,c) MIN(a,MIN(b,c))

typedef struct		s_rgb
{
	double	r;
	double	g;
	double	b;
}					t_rgb;

typedef struct		s_hsl
{
	double			h;
	double			s;
	double			l;
}					t_hsl;

typedef struct		s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

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


t_color			color(t_rgb r);
t_rgb   		rgb(double r, double g, double b);
t_hsl			hsl(double h, double s, double l);
t_hsv			hsv(double h, double s, double v);

t_hsl			rgbtohsl(t_rgb c);
t_rgb			hsvtorgb(t_hsv hsv);
t_rgb			hsltorgb(t_hsl h);

t_rgb			rgb_sub(t_rgb a, t_rgb b);
t_rgb			rgb_mult(t_rgb v, double b);
t_rgb			rgb_cos(t_rgb v);
t_rgb			rgb_add(t_rgb a, t_rgb b);
t_rgb			rgb_add2(t_rgb a, double d);
t_rgb			linear_inter(t_rgb v0, t_rgb v1, double t);

#endif