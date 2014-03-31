/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:25:36 by aleger            #+#    #+#             */
/*   Updated: 2014/02/04 03:34:43 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char *s)
{
	int		i;
	int		j;
	char	*n;

	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0)
		j--;
	n = ft_strsub(s, i, (j - i) + 1);
	if (!n)
		return (ft_strdup(""));
	ft_strdel(&s);
	return (n);
}
