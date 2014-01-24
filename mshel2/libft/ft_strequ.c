/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:37:25 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/21 19:20:47 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strequ(char const *s1, char const *s2)
{
	char const	*x;
	char const	*y;
	int			i;

	x = s1;
	y = s2;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (x[i] == y[i])
	{
		if (x[i] == '\0' && y[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
