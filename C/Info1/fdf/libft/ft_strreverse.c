/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:41:13 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strreverse(const char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	while (s[i] != '\0')
	{
		str[i] = s[len - 1];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
