/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 23:49:23 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:57:45 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strrev(char const *s)
{
	unsigned int	i;
	int				j;
	char			*rev;

	rev = (char *)malloc(ft_strlen(s) + 1);
	if (!rev)
		return (NULL);
	i = 0;
	j = 1;
	while (i < ft_strlen(s))
	{
		*(rev + i) = *(s + (ft_strlen(s) - j));
		i++;
		j++;
	}
	*(rev + i) = '\0';
	return (rev);
}
