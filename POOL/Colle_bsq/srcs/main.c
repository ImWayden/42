/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 14:18:09 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 14:18:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "bsq.h"

void		ft_main(char *str)
{
	t_bsq	*bsq;

	bsq = NULL;
	if ((bsq = parser(str)))
		before_bsq(&bsq);
	else
		write(2, "Map Error\n", 10);
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			ft_main(argv[i]);
			i++;
		}
	}
	else
		ft_main(NULL);
	return (0);
}
