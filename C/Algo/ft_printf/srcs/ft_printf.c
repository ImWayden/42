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

static int		c_option(int c)
{
	ft_putchar((unsigned char)c);
	return (1);
}

static int		s_option(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

static int		dioux_option(int i, char c)
{
	char		*str;
	char		*str1;

	str = NULL;
	str1 = NULL;
	if (c == 'i' || c == 'd' || c == 'u')
		str = ft_itoa(i);
	else if (c == 'o')
	{
		ft_changebase(&str1, (unsigned int)i, 8, 1);
		str = ft_strjoin("0", str1);
	}
	else if (c == 'x' || c == 'X')
	{
		ft_changebase(&str1, (unsigned int)i, 16, 1);
		str = ft_strjoin("0x", str1);
	}
	ft_putstr(str);
	i = ft_strlen(str);
	ft_memdel((void **)&str);
	ft_memdel((void **)&str1);
	return (i);
}

static int		print_center(va_list va, t_lex *list)
{
	int			j;
	char		c;

	j = ft_strlen(list->name) - 1;
	c = list->name[j];
	if (c == 'c')
		return (c_option(va_arg (va, int)));
	else if (c == 's')
		return (s_option(va_arg (va, char *)));
	else if (c == 'i' || c == 'd' || c == 'u' || c == 'o' || c == 'x'
		|| c == 'X')
		return (dioux_option(va_arg (va, int), list->name[j]));
	else
	{
		ft_putchar(c);
		return (1);
	}
}

int				ft_printf(char *str, ...)
{
	va_list		va;
	t_lex		*list;
	t_lex		*tmp;
	int			i;

	i = 0;
	va_start (va, str);
	list = lexer(str);
	tmp = list;
	while (tmp)
	{
		if (tmp->name[0] != '%' || !ft_strcmp(tmp->name, "%"))
		{
			ft_putstr(tmp->name);
			i += ft_strlen(tmp->name);
		}
		else
			i += print_center(va, tmp);
		dell_list(&tmp);
	}
	va_end (va);
	return (i);
}
