/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:23:09 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:11:54 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	else
		ft_bzero(str, (size + 1));
	return (str);
}
