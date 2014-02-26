/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 19:50:29 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:29:26 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char				*ft_strdup(const char *src)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = (char *)malloc(sizeof(char *) * (ft_strlen(src)) + 1);
	while (i < (ft_strlen(src) + 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
