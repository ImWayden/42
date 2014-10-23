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

/*int		ft_put(t_list *list, char *str, ...)
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
}*/

int		ft_printf(char *str, ...)
{
	va_list va;
   	t_lex		*list;
   	t_lex		*tmp;
   	int 	i;

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
		if ((tmp = tmp->next) == list)
			break;
	}
	va_end (va);
	return (i);
}

