/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:03:59 by msarr             #+#    #+#             */
/*   Updated: 2013/11/21 15:04:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static char	*ft_positive(char *str, int i, int *n)
{
	ft_putnbr(i);

	if (*n < 0)
	{
		*n = *n * -1;
		str = (char *) malloc(sizeof(char) * (i + 2));
		str[0] = '-';
		str[i + 1] = '\0';
	}
	else
	{
		
		str = (char *) malloc(sizeof(char) * (i + 1));
		str[i] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int 	n_cpy;

	i = 0;
	str = NULL;
	n_cpy = n;
	while (n_cpy)
	{
		n_cpy = n_cpy / 10;
		i++;	
	}
	if (n == 0)
		i = 1;
	n_cpy = n;
	ft_putnbr(i);
	str = ft_positive(str,i,&n_cpy);
	i = ft_strlen(str) ;
	ft_putnbr(i);
	while (str[i] != '-' && str[i])
	{
		str[i] = (n_cpy % 10 ) + '0';
		n_cpy = n_cpy / 10;
		i--;
	}
	
	return(str);
}
