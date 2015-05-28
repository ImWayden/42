/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 11:51:28 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/03 15:51:13 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "arkanoid.h"

void			ft_bonus(float ratio)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    	glColor3f(1.f, 0.f, 0.f);
    	glVertex3f(-0.04f, -0.02f, 0.f);
    	glColor3f(0.f, 1.f, 0.f);
    	glVertex3f(0.04f, -0.02f, 0.f);
    	glColor3f(1.f, 1.f, 0.f);
    	glVertex3f(0.f, 0.04f, 0.f);
    glEnd();
}

void			ft_balle()
{
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    	glColor3f(1.0f,1.0f,1.0f);
    	glVertex3f(-0.2f, -0.7f, 0.0f);
    glEnd();
}

void			ft_raquette()
{
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glTranslatef(g_xtrans, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    	glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.2f, -1.0f, 0.0f);
    	glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.0f, -1.0f, 0.0f);
    	glColor3f(1.f, 0.f, 1.f);
		glVertex3f(0.0f, -0.95f, 0.0f);
    	glColor3f(0.f, 0.f, 1.f);
		glVertex3f(-0.2f, -0.95f, 0.0f);
    glEnd();
}

void            ft_rect(float x, float y, float r, float g)
{
    float       x2;

    x2 = x + 0.17;
    glLoadIdentity();
    glTranslatef(1.0f, 0.1f, 0.0f);
    glColor3f(r, g, 0.0f);
    glRectf(x, y, x2, 0.07f);
}
