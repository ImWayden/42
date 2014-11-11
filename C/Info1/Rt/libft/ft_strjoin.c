/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 14:34:07 by atouzeau          #+#    #+#             */
/*   Updated: 2014/01/26 18:04:09 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(ft_strlen(s1) + 1);
	ft_strcat(ft_strcpy(tmp, s1), s2);
	if (!tmp)
		return (NULL);
	return (tmp);
}
