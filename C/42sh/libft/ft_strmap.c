/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:11:33 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 15:21:07 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = ft_strnew(i);
	if (str)
	{
		while (i)
		{
			i--;
			str[i] = f(s[i]);
		}
	}
	return (str);
}
