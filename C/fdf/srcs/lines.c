/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:43:29 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/27 22:31:17 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_nbr_line_col(char *str, t_env *env)
{
	int			i;
	int			j;
	char		**tmp;

	j = -1;
	env->nbr_line = 0;
	env->nbr_col = 0;
	env->fd = open(str, O_RDONLY);
	env->tab = (int *)malloc(sizeof(*tmp) * 1000);
	while (ft_get_next_line(env->fd, &env->line))
	{
		i = 0;
		tmp = ft_strsplit(env->line, ' ');
		ft_putstr(env->line);
		ft_putchar('\n');
		while (tmp[i])
			i++;
		env->nbr_line++;
		i = -1;
		while (tmp[++i])
			env->tab[++j] = ft_atoi(tmp[i]);
	}
	env->nbr_col = i;
}

void			ft_put_line(int w1, int h1, int w2, int h2, t_env env)
{
	int			x;

	x = w1;
	while (x <= w2)
	{
		mlx_pixel_put(env.ptr, env.win,  x, h1 + ((h2 - h1) * (x - w1))
						/ (w2 - w1), 0x66CC66);
		x++;
	}
}

void			ft_put_line2(int w1, int h1, int w2, int h2, t_env env)
{
	int			y;

	y = h1;
	while (y <= h2)
	{
		mlx_pixel_put(env.ptr, env.win, w1 + ((w2 - w1) * (y - h1))
						/ (h2 - h1), y, 0x66CC66);
		y++;
	}
}

void			fake_expose(t_env env)
{
	while (env.count < env.nbr_col * env.nbr_line)
	{
		env.width1 =  (env.tab[env.count] * -1)  + (PADDING
						* (env.count % env.nbr_col)) + 30;
		env.height1 = (env.tab[env.count] * -1)  + (PADDING
						* (env.count / env.nbr_col)) + 30;
		env.count++;
		env.width2 =  (env.tab[env.count] * -1)  + (PADDING
						* (env.count % env.nbr_col)) + 30;
		env.height2 = (env.tab[env.count] * -1)  + (PADDING
						* (env.count / env.nbr_col)) + 30;
		env.width3 = (env.tab[env.count + (env.nbr_col - 1)]
						* -1) + (PADDING * ((env.count + (env.nbr_col - 1))
												% env.nbr_col)) + 30;
		env.height3 = (env.tab[env.count + (env.nbr_col - 1)]
						* -1)  + (PADDING * ((env.count + (env.nbr_col - 1))
												/ env.nbr_col)) + 30;
		ft_put_line(env.width1, env.height1, env.width2, env.height2, env);
		if (env.count < 191)
			ft_put_line2(env.width1, env.height1, env.width3, env.height3, env);
		mlx_pixel_put(env.ptr, env.win, env.width1, env.height1, 0xFFFFFF);
	}
}
