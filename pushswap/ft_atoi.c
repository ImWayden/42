/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:56:17 by msarr             #+#    #+#             */
/*   Updated: 2013/11/20 11:19:29 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_atoi(const char *str)
{
	int		rslt;
	int		s;

	rslt = 0;
	s = 1;
	while (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\v'
		|| *str == '\n' || *str == '\t')
		str++;

	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		rslt = rslt * 10 + (*str++ - '0');
	return (s * rslt);
}
