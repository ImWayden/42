/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 15:22:24 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 15:22:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	tmp1;
	unsigned int	tmp2;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	tmp1 = ft_strlen(dest);
	tmp2 = ft_strlen(src);
	i = 0;
	j = tmp1;
	k = size - tmp1 - 1;
	if (size > tmp1)
	{
		while (i < k)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
		return (tmp1 + tmp2);
	}
	return (tmp2 + size);
}
