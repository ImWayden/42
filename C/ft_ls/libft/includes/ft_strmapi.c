/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:38:11 by msarr             #+#    #+#             */
/*   Updated: 2013/11/27 10:38:16 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = (char *) malloc(sizeof(*s) * (i + 1));
	if (!str)
		return (NULL);
	else
	{
		str[i] = '\0';
		i = 0;
		while (s[i])
		{
			str[i] = f(i,s[i]);
			i++;
		}
	}
	return (str);
}
