/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:28:47 by aleger            #+#    #+#             */
/*   Updated: 2014/01/04 00:25:42 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	val_change(int val, int signe)
{
	if (signe == 1)
		return (val * -1);
	return (val);
}

int			ft_atoi(const char *str)
{
	int		is_neg;
	int		val;

	val = 0;
	is_neg = 0;
	while (*str == ' ' || *str == '\v' || *str == '\t'
			|| *str == '\r' || *str == '\f' || *str == '\n')
		str++;
	if ((*str < 48 || *str > 57) && (*str != '-') && (*str != '+'))
		return (0);
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		val = (val * 10) + (*str - 48) % 10;
		str++;
	}
	return (val_change(val, is_neg));
}
