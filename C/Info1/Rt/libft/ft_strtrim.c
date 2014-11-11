/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:09:06 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:05:56 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		i2;
	char	*tmp;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	i2 = ft_strlen((char *)s) - 1;
	while (s[i2] == ' ' || s[i2] == '\n' || s[i2] == '\t')
		i2--;
	if (i2 < 0)
	{
		tmp = (char *)malloc(sizeof(char));
		*tmp = '\0';
		return (tmp);
	}
	tmp = (char *)ft_memalloc(i2 - i + 1);
	tmp = ft_strsub((char *)s, i, (i2 - i + 1));
	return (tmp);
}
