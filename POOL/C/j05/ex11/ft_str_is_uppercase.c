/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 15:05:11 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 15:05:14 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int			ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isupper(str[i]))
			return (0);
		i++;
	}
	return (1);
}
