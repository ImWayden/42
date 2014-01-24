/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:22:22 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/21 19:21:52 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cpy;
	int		i;
	char	*x;

	x = "ZAZ";
	if (s == NULL)
		return (x);
	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen((char *)s) + 1));
	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			cpy[i] = f(i, s[i]);
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}
