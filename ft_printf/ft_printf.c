/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:42:00 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:42:03 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnstr(char **str , char c)
{
	int		i;

	i = 0;
	while (**str && **str != c)
	{
		write(1, *str, 1);
		(*str)++;
		i++;
	}
	if (**str)
		(*str)++;
	return (i);
}

void ft_simplify(va_list va, int *i, char **str, t_list *list)
{
	*i = *i + ft_putnstr(str, '%');
	if (ft_isoption(*str, list) && (*list).name == 's')
		*i = *i + ft_put(list, *str, va_arg (va, char *));
	else if (ft_isoption(*str, list) && (*list).name == 'c')
		*i = *i + ft_put(list, *str, va_arg (va, int));
	else if	(ft_isoption(*str, list)
			&& ((*list).name == 'd'|| (*list).name == 'i'))
		*i = *i + ft_put(list, *str, va_arg (va, int));
	else if (ft_isoption(*str, list)
			&& ((*list).name == 'x' || (*list).name == 'p'))
		*i = *i + ft_put(list, *str, va_arg (va, size_t));
	else if (ft_isoption(*str, list) && (*list).name == 'o')
		*i = *i + ft_put(list, *str, va_arg (va, size_t));
	else if (**str == '%' && *(*str - 1) == '%')
	{
		ft_putstr("%");
		(*i)++;
	}
}

int		ft_printf(char *str, ...)
{
	va_list va;
   	t_list		*list;
   	int 	i;

   	i = 0;
   	va_start (va, str);
	list = ft_recup(str);
	while (*str)
	{
		ft_simplify(va, &i, &str, list);
		ft_verif(&str, &list);
	}
	va_end (va);
	return (i);
}

