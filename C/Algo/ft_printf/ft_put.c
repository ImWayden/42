/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:59 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:57:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put(t_list *list, char *str, ...)
{
	va_list va;
	int		i;
	char	*tmp;

	va_start (va, str);
	if ((*list).name == 's')
		tmp = va_arg(va, char *);
	else if ((*list).name == 'c')
	{
		tmp = ft_strnew(1);
		*tmp = (char)(va_arg(va, int));
	}
	else if ((*list).name == 'o')
		tmp = ft_octal((int )va_arg(va, size_t));
	else if ((*list).name == 'x')
		tmp = ft_hexa(va_arg(va, size_t));
	else if ((*list).name == 'p')
		tmp = ft_strjoin("0x", ft_hexa(va_arg(va, size_t)));
	else
		tmp = ft_itoa(va_arg(va, int));
	i = ft_strlen(tmp);
	ft_putstr(tmp);
	va_end(va);
	return (i);
}
