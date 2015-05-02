/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:09:35 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/02 06:01:42 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			ft_intro(void)
{
	ft_putstr(CYAN"   _____         __          __");
	ft_putendl("_.                .__    .___");
	ft_putstr("  /  _  \\_______|  | _______ \\_ |");
	ft_putendl("_________  ____ |__| __| _/");
	ft_putstr(" /  /_\\  \\_  __ \\  |/ /\\__  \\ ");
	ft_putendl("| __ \\_  __ \\/  _ \\|  |/ __ |");
	ft_putstr("/    |    \\  | \\/    <  / __ \\| ");
	ft_putendl("\\_\\ \\  | \\(  <_> )  / /_/ |");
	ft_putstr("\\____|__  /__|  |__|_ \\(____  /__");
	ft_putendl("_  /__|   \\____/|__\\____ |");
	ft_putstr("        \\/           \\/     \\/  ");
	ft_putendl("  \\/                     \\/"STOP);
	ft_print_purple("		Bienvenue sur Arkanobroïd !");
}

void			triangle(GLFWwindow* window)
{
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}

void			rectangle(GLFWwindow* window)
{
	
}

int				main(int ac, char **av)
{
    GLFWwindow*	window;

	(void)av;
	if (ac == 1)
	{
		ft_intro();
		if(!glfwInit())
		{
		    ft_print_red("Failed to initialize GLFW\n");
		    return (ERROR);
		}
	    window = glfwCreateWindow(640, 480, "Arkanoid", NULL, NULL);
	    if (!window)
	    {
	        glfwTerminate();
	        return (ERROR);
	    }
	    glfwMakeContextCurrent(window);
    	glfwSwapInterval(1);
	    while ((glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	    		&& (!glfwWindowShouldClose(window)))
	    {
	    	// code
	    	triangle(window);

    		glfwSwapBuffers(window);
	        glfwPollEvents();
	    }
    	glfwDestroyWindow(window);
	    glfwTerminate();
	    return (0);
	}
	return (0);
}
