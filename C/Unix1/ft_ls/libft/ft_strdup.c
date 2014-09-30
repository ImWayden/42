/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 12:29:08 by msarr             #+#    #+#             */
/*   Updated: 2014/03/06 08:50:35 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = ft_strlen(s1);
	cpy = ft_strnew(i);
	i = 0;
	while (cpy && s1 && s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}
