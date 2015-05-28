/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:48:46 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/03 16:55:34 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		ft_keys()
{
	ft_print_red("Voici un descriptif des touches disponibles :");
	ft_print_pnobs("ESC ou Q = ");
	ft_print_green("Quitter");
	ft_print_pnobs("A ou LEFT = ");
	ft_print_green("Déplacer la raquette vers la gauche");
	ft_print_pnobs("D ou RIGHT = ");
	ft_print_green("Déplacer la raquette vers la droite");
	ft_print_pnobs("SPACE = ");
	ft_print_green("Minimiser");
	ft_print_pnobs("K = ");
	ft_print_green("Augmenter le score");
	ft_print_pnobs("L = ");
	ft_print_green("Perdre une vie");
}

static void		ft_intro()
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
	ft_print_purple("		Bienvenue sur Arkabroïd !\n");
	ft_keys();
}

static int		ft_check_init()
{
	if (!glfwInit())
	{
	    ft_print_red("Failed to initialize GLFW");
	    return (ERROR);
	}
	return (0);
}

int				ft_check_window(GLFWwindow* window)
{
    if (!window)
    {
        glfwTerminate();
        return (ERROR);
    }
	return (0);
}

int				ft_init()
{
	ft_intro();
	g_xtrans = 0.0f;
	g_score = 0;
	g_life = 3;
	if (ft_check_init() == -1)
		return (ERROR);
	return (EXIT_SUCCESS);
}

