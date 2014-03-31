/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:57:41 by aleger            #+#    #+#             */
/*   Updated: 2014/01/26 09:48:27 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			s_case(char *s, t_data *data)
{
	if (data->space)
		data->padding = (ft_atoi(data->space) - ft_strlen(s));
	if (!s)
	{
		if (data->space && (data->fpadd == 0 || data->fpadd == 3))
			data->ret += print_spaces((data->padding - 5), data);
		ft_putstr("(null)");
		if (data->space && data->fpadd == 1)
			data->ret += print_spaces((data->padding - 5), data);
		return (data->ret + 6);
	}
	if (data->space && (data->fpadd == 0 || data->fpadd == 3))
		data->ret += print_spaces(data->padding, data);
	ft_putstr(s);
	data->ret += ft_strlen(s);
	if (data->space && data->fpadd == 1)
		data->ret += print_spaces(data->padding, data);
	return (data->ret);
}

int			d_case(int d, t_data *data)
{
	int		ret;

	ret = ft_strlen(ft_itoa(d));
	if (data->space)
		data->padding = (ft_atoi(data->space) - ret);
	if (data->space && (data->fpadd == 0 || data->fpadd == 3))
	{
		if (data->fpadd == 3)
		{
			data->ret += print_spaces((data->padding - 1), data);
			ft_putchar('+');
		}
		else
			data->ret += print_spaces(data->padding, data);
	}
	ft_putnbr(d);
	data->ret += ret;
	if (data->space && data->fpadd == 1)
		data->ret += print_spaces(data->padding, data);
	return (data->ret);
}

int			c_case(int c, t_data *data)
{
	if (data->space)
		data->padding = (ft_atoi(data->space) - 1);
	if (data->space && (data->fpadd == 0 || data->fpadd == 3))
		data->ret += print_spaces(data->padding, data);
	ft_putchar(c);
	if (data->space && data->fpadd == 1)
		data->ret += print_spaces(data->padding, data);
	return (data->ret + 1);
}

int			u_case(unsigned int u, t_data *data)
{
	int		ret;

	ret = ft_strlen(ft_uitoa(u));
	if (data->space)
		data->padding = (ft_atoi(data->space) - ret);
	if (data->space && (data->fpadd == 0 || data->fpadd == 3))
	{
		if (data->fpadd == 3)
		{
			data->ret += print_spaces((data->padding - 1), data);
			ft_putchar('+');
		}
		else
			data->ret += print_spaces(data->padding, data);
	}
	ft_putstr(ft_uitoa(u));
	data->ret += ret;
	if (data->space && data->fpadd == 1)
		data->ret += print_spaces(data->padding, data);
	return (data->ret);
}

int			o_case(unsigned int o, t_data *data)
{
	int		ret;

	ret = ft_strlen(ft_uotoa(o));
	if (data->space)
		data->padding = (ft_atoi(data->space) - ret);
	if (data->space && (data->fpadd == 0 || data->fpadd == 3))
	{
		if (data->fpadd == 3)
		{
			data->ret += print_spaces(data->padding, data);
			ft_putchar('+');
		}
		else
			data->ret += print_spaces(data->padding, data);
	}
	ft_putstr(ft_uotoa(o));
	data->ret += ret;
	if (data->space && data->fpadd == 1)
		data->ret += print_spaces(data->padding, data);
	return (data->ret);
}
