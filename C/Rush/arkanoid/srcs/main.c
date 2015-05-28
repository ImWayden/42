/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:09:35 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/03 16:53:33 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		ft_config(GLFWwindow* window)
{
    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	ft_callbacks(window);
}

static void		ft_dothetrick(GLFWwindow* window)
{
	ft_render(window);
	glfwSwapBuffers(window);
    glfwPollEvents();
}

static void		ft_end(GLFWwindow* window)
{
	glfwDestroyWindow(window);
    glfwTerminate();
}

int				main(int ac, char **av)
{
    GLFWwindow*	window;

	(void)av;
	if (ac == 1)
	{
		if (ft_init() == -1)
			return(ERROR);
	    window = glfwCreateWindow(SCREEN_X, SCREEN_Y, "Arkabroid", NULL, NULL);
		if (ft_check_window(window) == -1)
			return (ERROR);
		ft_config(window);
	    while ((!glfwWindowShouldClose(window)))
	    	ft_dothetrick(window);
	    ft_end(window);
	}
	return (EXIT_SUCCESS);
}
