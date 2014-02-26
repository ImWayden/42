/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recupwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 16:57:18 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 17:51:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ord_alphlong.h"

char		*ft_recupwords(char **str)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	int		j;

	tmp = *str;
	while (*tmp)
	{
		i = 0;
		while (*tmp != ' ')
		{
			tmp++;
			i++;
		}
		if (i)
		{
			tmp2 = (char *)malloc(sizeof(char) * (i + 1));
			j = 0;
			while (*str != tmp)
			{
				tmp2[j] = **str;
				(*str)++;
				j++;
			}
			tmp2[j] = '\0';
			return (tmp2);
		}
		tmp++;
		(*str)++;
	}
	return (NULL);
}
