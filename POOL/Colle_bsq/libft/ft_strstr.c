/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:08:18 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 14:31:08 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		j;
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	j = ft_strlen(tmp2);
	if (j == 0)
		return (tmp1);
	while (*tmp1 && (ft_strlen(tmp1) >= j))
	{
		if (ft_strncmp(tmp1, tmp2, j))
			tmp1++;
		else
			return ((char *)tmp1);
	}
	return (NULL);
}
