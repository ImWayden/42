/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:59:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/23 23:18:35 by msarr            ###   ########.fr       */
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
	c->fov = c->focal;
   	c->focal = -(SCREEN_W / ( 2 * tan (c->fov / 2)));
   	c->upleft = new(-SCREEN_W / 2, SCREEN_H / 2, c->pos.z);
	c->upright = new(SCREEN_W / 2, SCREEN_H / 2, c->pos.z);
	c->downright = new(SCREEN_W / 2, -SCREEN_H / 2, c->pos.z);
	c->downleft = new(-SCREEN_W / 2, -SCREEN_H / 2, c->pos.z);
    c->dir = sub(c->lookat, c->pos);
    c->upleft = add(c->upleft, mult2(c->dir, c->focal));
	c->upright = mult(c->upright, add(c->pos, c->dir));
	c->downright = mult(c->downright, add(c->pos, c->dir));
	c->downleft = mult(c->downleft, add(c->pos, c->dir));
   // c->upleft = sub(c->upleft, c->pos);
	//c->upright = sub(c->upright, c->pos);
	//c->downright = sub(c->downright, c->pos);
	//c->downleft = sub(c->downleft, c->pos);
   	printf("distance focale : %.1f\n", c->focal);
   	printf("vecteur dir : %lf %lf %lf\n", c->dir.x, c->dir.y, c->dir.z);
   	printf("vecteur upleft : %lf %lf %lf\n", c->upleft.x, c->upleft.y, c->upleft.z);
   	printf("vecteur upleft : %lf %lf %lf\n", c->upright.x, c->upleft.y, c->upleft.z);
   	exit(2);
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
