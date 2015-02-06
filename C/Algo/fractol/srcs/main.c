/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:47:46 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 14:47:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}
/*
 //get the time and old time for time dependent input
        oldTime = time;
        time = getTicks();
        frameTime = time - oldTime;
        //no key was pressed yet
        keyPressed = 0;
        readKeys();
        //ZOOM keys
        if(inkeys[SDLK_KP_PLUS])  {zoom *= pow(1.001, frameTime); keyPressed = 1;}
        if(inkeys[SDLK_KP_MINUS]) {zoom /= pow(1.001, frameTime); keyPressed = 1;}
        //MOVE keys
        if(inkeys[SDLK_DOWN])  {moveY += 0.0003 * frameTime / zoom; keyPressed = 1;}
        if(inkeys[SDLK_UP])    {moveY -= 0.0003 * frameTime / zoom; keyPressed = 1;}
        if(inkeys[SDLK_RIGHT]) {moveX += 0.0003 * frameTime / zoom; keyPressed = 1;}
        if(inkeys[SDLK_LEFT])  {moveX -= 0.0003 * frameTime / zoom; keyPressed = 1;}
        //CHANGE SHAPE keys
        if(inkeys[SDLK_KP2]) {cIm += 0.0002 * frameTime / zoom; keyPressed = 1;}
        if(inkeys[SDLK_KP8]) {cIm -= 0.0002 * frameTime / zoom; keyPressed = 1;}
        if(inkeys[SDLK_KP6]) {cRe += 0.0002 * frameTime / zoom; keyPressed = 1;}
        if(inkeys[SDLK_KP4]) {cRe -= 0.0002 * frameTime / zoom; keyPressed = 1;}
        //keys to change number of iterations
        if(inkeys[SDLK_KP_MULTIPLY] && keyReleased) {maxIterations *= 2; keyReleased = 0;}
        if(inkeys[SDLK_KP_DIVIDE] && keyReleased)   {if(maxIterations > 2) maxIterations /= 2; keyReleased = 0;}
        //key to change the text options
        if(inkeys[SDLK_F1] && keyReleased) {showText++; showText %= 3; keyReleased = 0;}
        //enable keyReleased again if the keys above are released
        if(!inkeys[SDLK_KP_MULTIPLY] && !inkeys[SDLK_KP_DIVIDE] && !inkeys[SDLK_F1]) keyReleased = 1;
*/

int					mouse_button(int button, int x, int y, t_env *env)
{
	if (button && x && y && env->conf)
	{
		env->conf++;
		main_mandel(env);
	}
	return (0);
}

int				mouse_move(int x, int y, t_env *env)
{
	(void)env;
	ft_putstr("mouse : ");
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(" ok: ");
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}

int				main(int ac, char **av)
{
	t_env		env;

	if (ac == 2)
	{
		init(&env, av);
		//env.funct = pyramid;
		env.funct(&env);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_mouse_hook(env.win, mouse_button, &env);
		mlx_expose_hook(env.win, expose, &env);
		mlx_hook(env.win, MotionNotify, PointerMotionMask, mouse_move, &env);
		mlx_loop(env.ptr);
	}
	return (0);
}