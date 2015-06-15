/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 14:26:40 by msarr             #+#    #+#             */
/*   Updated: 2014/07/03 14:26:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

void		ft_print_comb2(void)
{
	int		nb1;
	int		nb2;

	nb1 = 0;
	while (nb1 <= 98)
	{
		nb2 = nb1 + 1;
		while (nb2 <= 99)
		{
			ft_putchar((nb1 / 10) + '0');
			ft_putchar((nb1 % 10) + '0');
			ft_putchar(' ');
			ft_putchar((nb2 / 10) + '0');
			ft_putchar((nb2 % 10) + '0');
			if (nb1 != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			nb2++;
		}
		nb1++;
	}
}
