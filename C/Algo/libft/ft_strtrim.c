/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:55:53 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 17:53:34 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		j;

	str = NULL;
	while (s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	j = ft_strlen((char *)s) - 1;
	while (s && j > -1 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	j++;
	str = ft_strnew(j);
	str = ft_strncpy(str, (char *)s, j);
	return (str);
}
