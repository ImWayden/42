/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:05:43 by aleger            #+#    #+#             */
/*   Updated: 2014/01/26 09:48:03 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void		kill_data(t_data *data, char *s)
{
	int		i;

	i = 0;
	while (data->s[i] != 0)
	{
		free(data->s[i]);
		data->s[i] = NULL;
		i++;
	}
	free(data->s);
	data->s = NULL;
	data->rest = NULL;
	free(data);
	data = NULL;
	free(s);
	s = NULL;
}

t_data		*init(t_data *data, char *s)
{
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->s = ft_strsplit(s, '%');
	data->ret = 0;
	data->i = 0;
	data->flag = '0';
	data->space = NULL;
	data->fpadd = 0;
	return (data);
}

int			print_rest(char *s, t_data *data)
{
	if (data->flag != '0')
	{
		data->rest = ft_strchr(s, data->flag);
		if (data->rest != NULL)
		{
			data->ret += ft_strlen(data->rest + 1);
			ft_putstr(data->rest + 1);
			return (data->ret);
		}
	}
	return (ft_strlen(s));
}

int			get_flag(char *s, t_data *data)
{
	if ((s[0] >= '0' && s[0] <= '9') || (s[0] == '-') || (s[0] == '+')
			|| (s[0] == ' '))
		data->space = space_case(&s, data);
	if (s[0] == 'c' && (data->flag = 'c'))
		data->ret = c_case(va_arg(data->ptr, int), data);
	else if (s[0] == 5 && (data->flag = 5))
		data->ret = c_case(37, data);
	else if (s[0] == 's' && (data->flag = 's'))
		data->ret = s_case(va_arg(data->ptr, char *), data);
	else if ((s[0] == 'd' || s[0] == 'i') && (s[0] = 'd') && (data->flag = 'd'))
		data->ret = d_case(va_arg(data->ptr, int), data);
	else if (s[0] == 'u' && (data->flag = 'u'))
		data->ret = u_case(va_arg(data->ptr, unsigned int), data);
	else if (s[0] == 'o' && (data->flag = 'o'))
		data->ret = o_case(va_arg(data->ptr, unsigned int), data);
	else if ((s[0] == 'x' || s[0] == 'X') && (data->flag = 'x'))
		data->ret = x_case(va_arg(data->ptr, unsigned int), data, s);
	else
		ft_putstr(s);
	return (print_rest(s, data));
}

int			ft_printf(const char *format, ...)
{
	t_data	*data;
	int		ret;
	char	*s;

	s = ft_strdup(format);
	s = format_mod(s);
	data = NULL;
	if (!(data = init(data, s)))
		return (0);
	va_start(data->ptr, format);
	va_copy(data->ptr2, data->ptr);
	while (data->s[data->i] != 0)
	{
		data->ret = get_flag(data->s[data->i], data);
		data->i++;
	}
	ret = data->ret;
	va_end(data->ptr);
	kill_data(data, s);
	return (ret);
}
