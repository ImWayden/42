/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 01:38:41 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/03 16:54:30 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static float    ft_getratio(GLFWwindow* window)
{
    float       ratio;
    int         width;
    int         height;

    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    return (ratio);
}

static void     ft_print_infos()
{
    char        *str;
    size_t      n;

    n = 0;
    glColor3d(1.0, 0.0, 0.0);
    glRasterPos2d(-0.2, 0.8);
    str = ft_strdup("Score = ");
    ft_strcat(str, ft_itoa(g_score));
    while (n < ft_strlen(str))
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[n]);
        ++n;
    }
    n = 0;
    str = ft_strdup(" / Vie = ");
    ft_strcat(str, ft_itoa(g_life));
    while (n < ft_strlen(str))
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[n]);
        ++n;
    }
}

void			ft_render(GLFWwindow* window)
{
    float       ratio;

    ratio = ft_getratio(window);
	ft_bonus(ratio);
	ft_balle();
	ft_raquette();
    ft_rect(-2.33f, 0.0f, 1.0f, 0.0f);
    ft_rect(-2.15f, 0.010f, 1.5f, 0.5f);
    ft_rect(-1.97f, 0.012f, 1.0f, 1.0f);
    ft_rect(-1.79f, 0.014f, 0.0f, 1.0f);
    ft_print_infos();
}
