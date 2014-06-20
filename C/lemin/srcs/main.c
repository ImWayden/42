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

int					main(void)
{
	t_lem			*lem;

	lem = parse();
	if (lem && lem->j && lem->lem_start && lem->lem_end)
		lemin(lem);
	else
		ft_putcolorstr("ERROR\n", RED);
	dellem(&lem);
	sleep(30);
	return (0);
}
