/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:20:04 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 17:56:11 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * (size + 1))))
		ft_bzero((void *)str, (size + 1));
	return (str);
}
