/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 13:10:51 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 13:10:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;

	i = 0;
	while (src && src[i] && n)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	if (n)
		dest[i] = '\0';
	return (dest);
}
