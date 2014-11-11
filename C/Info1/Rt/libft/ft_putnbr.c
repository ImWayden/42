/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 17:41:54 by atouzeau          #+#    #+#             */
/*   Updated: 2014/04/25 18:09:37 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_aff_a(char a, int p, int nb)
{
	int		n;

	n = 0;
	while (p != 0)
	{
		a = '0' + ((nb % (p * 10)) / p);
		p = p / 10;
		if (a != '0' || n != 0)
		{
			ft_putchar(a);
			n = n + 1;
		}
	}
}

void	ft_put_nbre(int nb)
{
	int		p;
	int		a;

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	p = 1000000000;
	a = '0' + ((nb % (p * 10)) / p);
	ft_aff_a(a, p, nb);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar ('0');
	else if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb == 2147483647)
		ft_putstr("2147483648");
	else
		ft_put_nbre(nb);
}
