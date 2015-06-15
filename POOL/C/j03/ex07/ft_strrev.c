/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/04 13:22:51 by msarr             #+#    #+#             */
/*   Updated: 2014/07/04 13:22:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char			*ft_strrev(char *str)
{
	int			i;
	int			j;
	char		swap;

	j = ft_strlen(str) - 1;
	i = 0;
	while (j > i)
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		i++;
		j--;
	}
}
