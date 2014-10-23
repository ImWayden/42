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

void	ft_dtoa(double x)
{
	int		y;
	int		z;
	char	*str;
	char	*str1;
	char	*str2;

	y = (int )x;
	x -= y;
	z = 0;
	while (x > 0 && z <= 214748362)
	{
		x = x * 10;
		z = (z * 10) + (int)x;
		x = x - (int)x;
	}
	str = ft_itoa(y);
	str1 = ft_itoa(z);
	str2 = ft_strjoin(str, ".");
	ft_memdel(&str);
	str = ft_strjoin(str2, str1);
	ft_memdel(&str2);
	ft_memdel(&str1);
	return (str);
}