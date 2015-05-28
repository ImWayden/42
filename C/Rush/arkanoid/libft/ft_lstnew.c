/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 18:50:33 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/26 00:29:26 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content)
		{
			if ((tmp->content = ft_memalloc(content_size)))
			{
				ft_memcpy(tmp->content, content, content_size);
				tmp->content_size = content_size;
			}
		}
		else
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		tmp->next = NULL;
	}
	return (tmp);
}
