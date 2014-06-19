/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:45:56 by msarr             #+#    #+#             */
/*   Updated: 2014/06/18 14:07:38 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int 				main()
{
	t_lem			*lem;

	lem = parse();
	if (lem && lem->start && lem->end && lem->j)
	{
		lemin(lem);
		dellem(&lem);
	}
	else if (lem)
	{
		if (lem && !lem->start)
			ft_putcolorstr("THERE IS NO START !\n", RED);
		else if (lem && !lem->end)
			ft_putcolorstr("THERE IS NO END !\n", RED);
		else if (lem && !lem->j)
			ft_putcolorstr("NO LEM TO SEND !\n", RED);
		dellem(&lem);
	}
	else
		ft_putcolorstr("WRONG MAP !\n", RED);
	return (0);
}
