/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:59:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/20 05:20:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static int		cam_exit()
{
	ft_putendl("cam needs 3 args");
	exit (0);
}

void		cam_setup(t_cam *c)
{
	c->fov = 60;
	c->up = new(0.0f, 1.0f, 0.0f);
	c->width = SCREEN_W;
   	c->height = SCREEN_H;
   	c->focal = -200;//-(SCREEN_W / ( 2 * tan (FOV / 2)));
   	//c->pos.z = c->focal;
    c->dir = sub(c->lookat, c->pos);
	c->right = mult(c->up, c->dir);
    c->up = mult(c->dir, c->right);
	c->upleft = sub(add(c->pos, add(mult2(c->dir, c->focal),
		mult2(c->up, (c->height / 2.0f)))), mult2(c->right, (c->width / 2.0f)));
   	printf("distance focale : %.1f\n", c->focal);
   	sleep(2);
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
