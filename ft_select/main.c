/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:52:29 by msarr             #+#    #+#             */
/*   Updated: 2014/01/03 14:52:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int 	main(int argc, char **argv, char **env)
{
	struct termios term;
	t_list			*list;

	if (argc > 1)
	{
		list = NULL;
		ft_recup(&argv[1], &list);
		if (ft_init(&term))
			return (-1);
		if (ft_config(&term))
			return (-1);
		ft_effect(list);
		if (ft_defconfig(&term))
			return (-1);
	}
	return (0);
}
