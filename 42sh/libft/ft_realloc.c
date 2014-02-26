/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:49:39 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:16:10 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_realloc(void *str, int size)
{
	str = realloc(str, size);
	if (str == NULL)
		ft_exit("Error : could not realloc.\n");
	return (str);
}