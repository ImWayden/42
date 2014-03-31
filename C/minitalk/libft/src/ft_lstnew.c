/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 00:43:56 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 14:05:12 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n;

	n = (t_list *)malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	if (!content)
	{
		n->content = NULL;
		n->content_size = 0;
		n->next = NULL;
	}
	else
	{
		n->content = (void *)content;
		n->content_size = content_size;
		n->next = NULL;
	}
	return (n);
}
