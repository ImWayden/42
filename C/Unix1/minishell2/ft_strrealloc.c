/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 14:12:25 by msarr             #+#    #+#             */
/*   Updated: 2013/12/08 14:12:29 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"

char	*ft_strrealloc(char **line, unsigned int len)
{
	int		i;
	char	*str;
	char *s2;

	i = ft_strlen(*line);
	s2 = *line;
	str = (char *) malloc(sizeof(char) * (i + len + 1));
	i = 0;
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	ft_memdel((void **)&s2);
	ft_bzero(&str[i], len + 1);
	return (str);
}
