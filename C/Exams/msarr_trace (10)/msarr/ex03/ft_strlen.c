
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 16:34:00 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 17:57:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ord_alphlong.h"

int		ft_strlen(char *s1)
{
	int		i;

	i = 0;
	while(*s1)
	{
		i++;
		s1++;
	}
	return (i);
}
