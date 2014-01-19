/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Stouf <Stouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:02:25 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/15 18:27:44 by Stouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define RGB_SKY 0x5EB6DD /*bleu ciel*/
# define RGB_FLOOR 0x183152 /*bleu fonce*/
# define RGB_WALL_N 0x8FCF3C /*vert*/
# define RGB_WALL_E 0xFF00B8 /*rose violet*/
# define RGB_WALL_O 0xFF5B2B /*orange*/
# define RGB_WALL_S 0xFFF168 /*jaune poussin*/
# define SCREEN_X 320.0
# define SCREEN_Y 200.0
# define WALL 64.0
# define ANGCHVI 60.0

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"

typedef struct      s_env
{
	int		argc;
	char	**argv;
	int		nbr_line;
	int		nbr_col;
	int		fd;
	char	*line;
	int		**tab;
	void	*mlx;
	void	*win;
	double  rayPosX;
    double  rayPosY;
    double  rayDirX;
    double  rayDirY;
    int     mapX;
    int     mapY;
    double  sideDistX;
    double  sideDistY;
    double  deltaDistX;
    double  deltaDistY;
    double  wallDist;
    int     stepX;
    int     stepY;
    int     hit;
    int     side;
    int     lineH;
    int     drawStart;
    int     drawEnd;
	double  cameraX;
    double  posX;
    double  posY;
    double  dirX;
    double  oldDirX;
    double  dirY;
    double  planeX;
    double  oldPlaneX;
    double  planeY;
}					t_env;

int     main(int argc, char **argv);
void    ft_stock_value(t_env *e);
void    ft_nbr_line_col(t_env *e);

#endif /* !WOLF3D_H */
