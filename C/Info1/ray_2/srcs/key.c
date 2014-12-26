/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:16:19 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 18:00:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

int					ft_key_press(int keycode, t_env *env)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == UP)
		env->forward = 1;
	if (keycode == 65307)
		exit(0);
	return (0);

}

int					ft_key_release(int keycode, t_env *env)
{
	if (keycode == UP)
		env->forward = 0;
	if (keycode == 65307)
		exit(0);
	return (0);
}
