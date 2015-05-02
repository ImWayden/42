/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:09:35 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/02 03:32:09 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
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
	    while ((glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	    		&& (!glfwWindowShouldClose(window)))
	    {
	    	// code

	        glfwPollEvents();
	    }
	    glfwTerminate();
	    return (0);
	}
	return (0);
}
