/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:37:21 by sraccah          ###   ########.fr       */
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
