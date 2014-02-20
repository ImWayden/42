/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:00:00 by aleger            #+#    #+#             */
/*   Updated: 2013/12/25 13:53:23 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	dst = ft_strcpy(dst, s1);
	return (dst);
}
