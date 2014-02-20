/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:05:49 by msarr             #+#    #+#             */
/*   Updated: 2013/12/22 14:05:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strreverse(const char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(*str) * (len + 1));
	while (s[i] != '\0')
	{
		str[i] = s[len - 1];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
