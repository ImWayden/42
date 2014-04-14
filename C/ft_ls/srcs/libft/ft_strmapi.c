/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:38:11 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 19:29:09 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			str[i] = f(i, s[i]);
		}
	}
	return (str);
}
