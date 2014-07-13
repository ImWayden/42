/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 14:59:55 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 14:59:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
