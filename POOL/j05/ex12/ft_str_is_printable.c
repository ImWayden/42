/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 15:09:52 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 15:09:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if ((c >= '!' && c <= '~') || c == ' ')
		return (1);
	else
		return (0);
}

int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		i++;
	}
	return (1);
}
