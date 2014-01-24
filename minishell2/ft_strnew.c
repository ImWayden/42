/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:20:04 by msarr             #+#    #+#             */
/*   Updated: 2013/11/26 13:20:14 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell2.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*tmp;

	str = NULL;
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		tmp = str;
		ft_bzero(tmp,size);
		return (str);
	}
	else
		return (str);
}
