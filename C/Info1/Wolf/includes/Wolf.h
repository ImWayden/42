/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:41:52 by msarr             #+#    #+#             */
/*   Updated: 2014/11/06 21:42:06 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
# define screenWidth 	512
# define screenHeight	384
# define mapWidth 		24
# define mapHeight 		24

typedef	struct	s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data;
	int			sizel;
	int			endian;
	int			bpp;

	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			texture[8];
	int			**worldMap;
	int			time;
	int			oldTime;
	double		cameraX;    
	double		rayPosX;
	double		rayPosY;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			texNum;
	int			mapX;
	int			mapY;
}				t_env;

int					raycaster(t_env *env);
void			draw(t_env *env, int x);

#endif
