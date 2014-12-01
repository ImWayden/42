/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:59:57 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 01:29:08 by msarr            ###   ########.fr       */
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
    t_vect	x_c;
    t_vect	u_c;
    t_vect	u_x;
    t_vect	u_y;
    double	z_p;
    t_vect	v_up;
    t_vect	c_0;


    x_c = c->pos;
    u_c = c->dir;
    z_p = c->focal;
    v_up = new(0.0, -1.0, 0.0);
    c_0 = add(x_c, mult2(u_c, z_p));
    u_x = unit(cross(u_c, v_up));
    u_y = cross(mult2(u_c, -1.0), u_x);
    c->center = c_0;
    c->pdir_x = u_x;
    c->pdir_y = u_y;
    //Vector3 u_z = vec3_mult(u_c, -1.0); // Normal to the view plane
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
			lex = get_pos(&cam->dir, lex);
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
	cam->width = SCREEN_W;
	cam->height = SCREEN_H;
	return (lex);
}
