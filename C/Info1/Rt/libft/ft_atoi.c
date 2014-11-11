/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:48:16 by atouzeau          #+#    #+#             */
/*   Updated: 2014/11/11 00:43:42 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		nb;
	int		nb_r;
	int		a;

	a = 1;
	nb_r = 0;
	nb = 0;
	while (*str > '9' || *str < '0')
	{
		if (*str == '-')
		{
			a = -a;
		}
		str = str + 1;
	}
	while (*str <= '9' && *str >= '0')
	{
		nb_r = nb_r * 10;
		nb = *str - '0';
		str = str + 1;
		nb_r = nb_r + nb;
	}
	nb_r = nb_r * a;
	return (nb_r);
}
