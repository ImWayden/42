/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:05:35 by sraccah           #+#    #+#             */
/*   Updated: 2013/12/03 19:05:37 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
			str[i] = f(s[i]);
			i++;
		}
	}
	return (str);
}
