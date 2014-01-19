/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:31:36 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:08:58 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = malloc(sizeof(*str) * size);
	if (!str)
		return (NULL);
	else
		ft_bzero(str, size);
	return (str);
}
