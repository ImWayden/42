/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:05:49 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:05:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_changebase(char **str, size_t i, size_t base, int len)
{
	char	*str1;

	str1 = "0123456789abcdef";
	if (i >= base)
	{
		len = ft_changebase(str, i / base, base, len + 1);
		i = i % base;
	}
	if (!(*str))
	{
		*str = ft_strnew(len);
		len = 0;
	}
	(*str)[len] = str1[i];
	return (len + 1);
}
