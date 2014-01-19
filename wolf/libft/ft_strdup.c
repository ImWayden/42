/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:35:07 by xmachado          #+#    #+#             */
/*   Updated: 2013/12/03 19:10:32 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*dup;

	dup = (char*)malloc (ft_strlen(str) + 1);
	ft_strcpy(dup, str);
	return (dup);
}
