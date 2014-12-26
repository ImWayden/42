/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:59:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/26 13:04:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

void		put_vect(char *str, t_vect v)
{
   	printf("%s : %lf %lf %lf\n", str, v.x, v.y, v.z);
}


static int		cam_exit()
{
	ft_putendl("cam needs 3 args");
	exit (0);
}

void		cam_setup(t_cam *c)
{
	c->fov = c->focal;
   	c->focal = -((double)SCREEN_W / ( 2.0 * tan(c->fov / 2.0)));
	c->up = new(0.0, 1.0, 0.0);
    c->dir = sub(c->lookat, c->pos);
   	c->dir = normal(c->dir);
   	c->screen = new(SCREEN_W, SCREEN_H, c->focal);
	c->upright = cross(c->up, c->dir);
	// De meme pour le "vrai" vecteur haut.
	c->up = cross(c->dir, c->upright);
	// Maintenant nous avons toutes les informations pour détérminer la position 
	// en haut à gauche du viewplane.
	c->upleft = add(c->pos, sub(add(mult2(c->dir, c->focal), mult2(c->up, ((double)SCREEN_H / 2.0))),
		mult2(c->upright, ((double)SCREEN_W / 2.0))));
}

t_lex			*get_cam(t_cam *cam, t_lex *lex)
{
	int			i;

	i = 0;
	while (lex)
	{
		if (!ft_strcmp(lex->str, "<POS>"))
			lex = get_pos(&cam->pos, lex);
		else if (!ft_strcmp(lex->str, "<ROT>"))
			lex = get_pos(&cam->lookat, lex);
		else if (!ft_strcmp(lex->str, "<FOC>") && (lex = lex->next))
		{
			cam->focal = get_nbr(lex->str);
			lex = lex->next;
		}
		else
			break ;
		i++;
	}
	if (i != 3)
		cam_exit();
	return (lex);
}
