/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 12:29:08 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 13:48:08 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	cpy = ft_strnew(ft_strlen(s1));
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}
