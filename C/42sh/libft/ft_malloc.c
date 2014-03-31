/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:49:39 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/05 18:21:05 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		*ft_mymalloc(int size)
{
	void		*tmp;

	tmp = (void *)malloc(size);
	if (tmp == NULL)
		ft_exit("Error : could not malloc.\n");
	return (tmp);
}