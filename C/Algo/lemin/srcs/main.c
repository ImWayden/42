/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/12/02 04:00:09 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "fdf.h"

int					main(void)
{
	t_lem			*lem;
	t_coord			coord;
	t_env			env;

	if ((lem = parse()))
	{
		lem->end->dist = 0;
		lemin(lem);
		coord.x = 24;
		coord.y =  24;
		env.e_x = lem->end->x;
		env.e_y = lem->end->y;
		env.room = lem->tab;
		fdf(env, coord);
	}
	return (0);
}
