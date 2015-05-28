/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 01:38:24 by sraccah           #+#    #+#             */
/*   Updated: 2015/05/03 16:47:11 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
    if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if ((key == GLFW_KEY_A || key == GLFW_KEY_LEFT) && (action == GLFW_REPEAT 
            || action == GLFW_PRESS))
    	if (g_xtrans >= -1.2f)
        	g_xtrans -= 0.1;
    if ((key == GLFW_KEY_D || key == GLFW_KEY_RIGHT) && (action == GLFW_REPEAT 
            || action == GLFW_PRESS))
    	if (g_xtrans < 1.5f)
        	g_xtrans += 0.1;
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        glfwIconifyWindow(window);
    if (key == GLFW_KEY_K && action == GLFW_PRESS)
    {
        g_score += 1;
        if (g_score > 1000)
            g_score = 0;
    }
    if (key == GLFW_KEY_L && action == GLFW_PRESS)
    {
        g_life -= 1;
        if (g_life < 0)
            g_life = 0;
    }
}

static void	cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
	glfwGetCursorPos(window, &xpos, &ypos);
}

void        ft_callbacks(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);
}
