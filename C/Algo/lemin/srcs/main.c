/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/12/03 20:18:36 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "fdf.h"

int					main(int argc, char **argv)
{
	t_lem			*lem;
	t_env			env;

	if ((lem = parse()))
	{
		lem->end->dist = 0;
		if (argc == 2 && !ft_strcmp(argv[1], "-g"))
			lem->g = 1;
		else
			lem->g = 0;
		lem->start->lem = 1;
		way(lem->end, lem);
		if (lem->start->dist < 1000)
		{
			if (lem->g)
				init(&env, lem);
			lemin(lem, env);
			return (0);
		}
	}
	ft_putstr("ERROR\n");
	return (0);
}
