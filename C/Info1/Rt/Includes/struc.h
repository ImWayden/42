/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:23:49 by atouzeau          #+#    #+#             */
/*   Updated: 2014/11/11 01:13:21 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H

typedef struct s_objet	t_objet;
typedef struct s_spot	t_spot;

typedef struct	s_color
{
	short		red;
	short		green;
	short		blue;
	short		new_red;
	short		new_green;
	short		new_blue;
}				t_color;

typedef struct	s_ppti
{
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_ppti;

typedef struct	s_rot
{
	double		rot_x;
	double		rot_y;
	double		rot_z;
}				t_rot;

typedef	struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

struct			s_objet
{
	int			nb;
	int			type;
	int			perturb;
	double		brill;
	double		middle;
	double		size;
	t_rot		rot;
	t_coord		coord;
	t_color		color;
	t_color		pm_color;
	t_color		ps_color;
	t_objet		*next;
};

typedef struct	s_vect
{
	double		v_x;
	double		v_y;
	double		v_z;
	double		n_x;
	double		n_y;
	double		n_z;
	double		lr;
}				t_vect;

typedef struct	s_utils
{
	double		amb;
	double		norme;
	t_vect		vect;
	t_vect		norm;
	t_coord		coord;
	t_spot		*spot;
	t_rot		eye_rot;
}				t_utils;

typedef struct	s_perlin
{
	double		a;
	double		b;
	double		c;
	double		d;
}				t_perlin;

typedef struct	s_k
{
	int			type;
	int			nb;
	double		reflex;
	double		k;
	double		ind;
	double		transp;
	short		brill;
	t_color		color;
}				t_k;

struct			s_spot
{
	t_coord		coord;
	t_color		color;
	t_spot		*next;
};

typedef struct	s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	double		amb;
	int			anti_alias;
	t_ppti		ppti;
	t_coord		eye_coord;
	t_rot		eye_rot;
	t_spot		*spot;
	t_objet		*objet;
}				t_param;

#endif
