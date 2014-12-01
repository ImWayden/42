/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:10:47 by msarr             #+#    #+#             */
/*   Updated: 2014/11/29 03:14:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

# define	SCREEN_H 256
# define	SCREEN_W 256

typedef struct	s_vect
{
	float			x;
	float			y;
	float			z;
	float			d;
	/* data */
}				t_vect;

typedef struct	s_obj
{
	int			diff_c;
	int			amb_c;
	int			reflex;
	int			spec;
	int			opac;
	/* data */
}				t_obj;

typedef struct	s_sphere
{
	t_vect		vect;
	t_vect		color;
	float		radius;
	/* data */
}				t_sphere;

typedef struct	s_light
{
	t_vect		vect;
	t_vect		color;
	float		i;
	/* data */
}				t_light;

typedef struct	s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data;
	int			sizel;
	int			endian;
	int			bpp;
	t_light		light;
	t_sphere	sphere1;
	t_sphere	sphere2;
	/* data */
}				t_env;

int				raytracer(t_env *env);
t_vect			*new_vect(t_vect tmp);
void			set_radius(t_sphere *sphere, float r);
void 			set_pos(t_vect *vect, float x, float y, float z);
void			setintensity(t_env *env, float pi);
void			set_color(t_vect *color, int r, int g, int b);
t_vect	 		*normal_at(t_sphere *sphere, float px,float py,float pz);
float			getIntensityAtAngle(t_light light, float px, float py, float pz, t_vect normal);
float			getIntensityAt(t_light light, float px,float py,float pz);
t_vect		 	*ray_sphere(t_sphere *sphere, float x1,float y1,float z1,float x2,float y2,float z2, int *ret);

#endif
