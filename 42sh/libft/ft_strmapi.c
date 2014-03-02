/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:05:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:12:41 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (i + 1));
	if (!str)
		return (NULL);
	else
	{
		str[i] = '\0';
		i = 0;
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
	}
	return (str);
}
