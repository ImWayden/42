/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 15:02:39 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 15:02:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int			ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_islower(str[i]))
			return (0);
		i++;
	}
	return (1);
}
