/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 00:37:24 by aleger            #+#    #+#             */
/*   Updated: 2014/01/26 09:48:25 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void		plus_case(char ***s, t_data *data)
{
	if (***s == '+' && (**s)++)
	{
		if (***s == '+' && (**s)++ && ***s != '-')
		{
			ft_putchar('+');
			data->ret += 1;
		}
		while (***s == '+')
			(**s)++;
		data->fpadd = 3;
	}
	if (***s == '-' && (**s)++ && ***s != '+')
	{
		if (***s == '-' && (**s)++ && ***s != '+')
		{
			ft_putchar('-');
			data->ret += 1;
		}
		while (***s == '-')
			(**s)++;
		data->fpadd = 1;
	}
}

char		*space_case(char **s, t_data *data)
{
	int		i;

	i = 0;
	if (**s == ' ')
		(*s)++;
	if (**s == '+' || **s == '-')
		plus_case(&s, data);
	if (!(data->space = (char *)malloc(0)))
		return (NULL);
	while (**s >= '0' && **s <= '9')
	{
		data->space = ft_realloc(data->space, i, i + 1);
		data->space[i] = **s;
		i++;
		(*s)++;
	}
	data->space[i] = '\0';
	return (data->space);
}

int			print_spaces(int n, t_data *data)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
	free(data->space);
	data->space = NULL;
	data->fpadd = 0;
	return (n);
}

int			x_case(int x, t_data *data, char *s)
{
	char	*to_hex;
	int		ret;

	ret = ft_strlen(ft_xtoa(x));
	if (data->space && data->fpadd == 0)
		data->ret += print_spaces((ft_atoi(data->space) - ret), data);
	if (*s == 'x')
	{
		ft_putstr(ft_xtoa(x));
		data->ret += ret;
	}
	else if (*s == 'X' && (*s = 'x'))
	{
		to_hex = ft_xtoa(x);
		while (*to_hex)
		{
			ft_putchar(ft_toupper(*to_hex));
			to_hex++;
		}
		data->ret += ret;
	}
	if (data->space && data->fpadd == 0)
		data->ret += print_spaces((ft_atoi(data->space) - ret), data);
	return (data->ret);
}
