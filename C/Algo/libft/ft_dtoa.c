/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:03:59 by msarr             #+#    #+#             */
/*   Updated: 2014/03/03 00:08:37 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int					ft_lintlen(long int n)
{
	long int		i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}

int					ft_floatlen(float n)
{
	long int		bv;
	long int		av;

	bv = n / 1;
	av = n - bv;
	return (ft_lintlen(av) + ft_lintlen(bv));
}

char				*ft_lintoa(long int n)
{
	long int		j;
	char			*str;

	j = ft_lintlen(n);
	if (n < 0)
	{
		j++;
		str = ft_strnew(j);
		*str = '-';
		n = -n;
	}
	else
		str = ft_strnew(j);
	if (!n)
		*str = '0';
	while (str && n && j)
	{
		j--;
		str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char				*ft_dtoa(double n, size_t i)
{
	long int		k;
	double			f;

	k = n / 1;
	f = n - k;
	k = i;
	while (i--)
		f = f * 10;
	if (f < 0)
		f = -f;
	if (!k)
		return (ft_lintoa(n));
	k = f;
	return (ft_strjoin(ft_strjoin(ft_lintoa(n), "."), ft_lintoa(k)));
}
