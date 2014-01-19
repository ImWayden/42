/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 21:13:22 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/18 21:22:14 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include				"libft.h"

char					*ft_strdup_nl(char *str)
{
	size_t			i;
	char			*cpy;

	i = 0;
	if (!(cpy = malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
