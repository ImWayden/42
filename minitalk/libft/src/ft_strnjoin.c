/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:49:14 by aleger            #+#    #+#             */
/*   Updated: 2014/01/14 18:49:48 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

char			*ft_strnjoin(int nb, const char *s, ...)
{
	char		*n;
	char		*tmp;
	va_list		ptr;
	bool		alloc_check;
	int			cur;

	va_start(ptr, s);
	alloc_check = false;
	cur = 0;
	if (!(n = (char *)malloc(sizeof(char *) * ft_strlen(s))))
		return (NULL);
	n = ft_strcpy(n, s);
	while (cur < nb && (tmp = va_arg(ptr, char *)) != NULL)
	{
		if (alloc_check == true)
			n = ft_realloc(n, ft_strlen(n), ft_strlen(n) + ft_strlen(tmp));
		if (n && (alloc_check = true))
			n = ft_strcat(n, tmp);
		else
			return (NULL);
		cur++;
	}
	va_end(ptr);
	return (n);
}
