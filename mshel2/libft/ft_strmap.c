/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 20:02:39 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:11:34 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			cpy[i] = f(s[i]);
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}
