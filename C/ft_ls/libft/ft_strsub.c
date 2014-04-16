/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:40:58 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 15:58:42 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = ft_strnew(len);
	i = 0;
	while (str && s[start] && i < (int)len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
