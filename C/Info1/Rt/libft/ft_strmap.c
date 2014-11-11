/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:44:42 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:04:38 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = (char *)malloc(sizeof(tmp) * (ft_strlen((char *)s) + 1));
	if (!tmp && !f)
		return (NULL);
	while (s[count])
	{
		tmp[count] = f((char)s[count]);
		count++;
	}
	tmp[count] = '\0';
	return (tmp);
}
