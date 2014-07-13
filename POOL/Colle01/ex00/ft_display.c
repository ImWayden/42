/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 13:19:41 by msarr             #+#    #+#             */
/*   Updated: 2014/07/12 13:19:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	while (str && *str)
	{
		ft_putchar(*str);
		str++;
	}
}

void				ft_display(char **av)
{
	int				i;
	int				j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(av[i][j]);
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
