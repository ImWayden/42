/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 07:10:32 by aleger            #+#    #+#             */
/*   Updated: 2014/01/20 05:03:13 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_realloc(void *ptr, size_t old, size_t new)
{
	void	*ptr2;

	if (!new && ptr)
	{
		free(ptr);
		return ((void *)malloc(new));
	}
	if (!ptr)
		return ((void *)malloc(new));
	if (!(ptr2 = (void *)malloc(new)))
		return (NULL);
	ft_memcpy(ptr2, ptr, old);
	free(ptr);
	ptr = NULL;
	return (ptr2);
}
