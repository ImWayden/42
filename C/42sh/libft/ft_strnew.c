/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:54:47 by sraccah           #+#    #+#             */
/*   Updated: 2013/11/25 10:54:47 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	char	*ptr;

	str = NULL;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		ptr = str;
		ft_bzero(ptr, size);
		return (str);
	}
	else
		return (str);
}
