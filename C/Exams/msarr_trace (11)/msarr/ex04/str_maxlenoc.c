/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 11:21:55 by exam              #+#    #+#             */
/*   Updated: 2014/01/30 12:16:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct		s_list
{
	char 			*str;
	struct s_list	next;
}					t_list;

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void		*ft_maxlenoc(char **s)
{
	int		i;
	int		j;

	i = 1;
	j = ft_strlen(str[0])
	while (str[i])
	{
		if (j > ft_strlen(str[i]))
				j = ft_strlen(str[j]);
		i++;
	}
	if (j)
	{
	}
	write(1, "\n", 1);
}
