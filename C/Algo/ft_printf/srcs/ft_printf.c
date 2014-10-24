/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:42:00 by msarr             #+#    #+#             */
/*   Updated: 2014/10/22 15:29:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_option(int c)
{
	ft_putchar(c);
	return (1);
}

int			print_center(va_list va, t_lex *list)
{
	int		j;

	j = ft_strlen(list->name) - 1;
	if (list->name[j] == 'c')
		return (c_option(va_arg (va, int)));
	if (list->name == 's')
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
}

int		ft_printf(char *str, ...)
{
	va_list va;
	t_lex		*list;
	t_lex		*tmp;
	int 		i;

	i = 0;
	va_start (va, str);
	list = lexer(str);
	tmp = list;
	while (list)
	{
		if (tmp->name[0] != '%' || !ft_strcmp(tmp->name, "%"))
		{
			ft_putstr(tmp->name);
			i += ft_strlen(tmp->name);
		}
		else
			i += print_center(va, tmp);
		if ((tmp = tmp->next) == list)
			break;
	}
	va_end (va);
	return (i);
}

