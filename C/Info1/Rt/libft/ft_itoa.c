/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 16:04:50 by atouzeau          #+#    #+#             */
/*   Updated: 2014/11/11 00:44:18 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n, int j)
{
	int		i;

	i = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (j)
	{
		i++;
	}
	return (i);
}

static void	norme_loop(char *str, int *n, int *i)
{
	while ((*n) != 0)
	{
		str[(*i)] = (*n) % 10 + '0';
		(*n) = (*n) / 10;
		(*i)--;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	j = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	i = get_length(n, j);
	str = malloc(sizeof(*str) * (i + 1));
	if (str)
	{
		str[i] = '\0';
		i--;
		str[i] = '0';
		norme_loop(str, &n, &i);
		str[0] = j ? '-' : str[0];
	}
	return (str);
}

