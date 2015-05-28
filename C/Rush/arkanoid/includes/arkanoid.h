/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:09:35 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/03 16:47:21 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# define GLFW_INCLUDE_GLU
# include <GLFW/glfw3.h>
 #include <GL/glu.h>
# include <GL/glut.h>

# include "libft.h"

# define SCREEN_X 	640
# define SCREEN_Y 	480

float 			g_xtrans;
int 			g_score;
int 			g_life;

/*
** callback.c
*/

void			ft_callbacks(GLFWwindow* window);

/*
** draw.c
*/

void			ft_bonus(float ratio);
void			ft_balle(void);
void			ft_raquette(void);
void            ft_rect(float x1, float r, float g, float b);

/*
** init.c
*/

int				ft_init(void);
int				ft_check_window(GLFWwindow* window);

/*
** render.c
*/

void			ft_render(GLFWwindow*	window);

#endif
