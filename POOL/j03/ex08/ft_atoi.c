/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/04 13:36:58 by msarr             #+#    #+#             */
/*   Updated: 2014/07/04 13:37:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int			rslt;
	int			s;

	rslt = 0;
	s = 1;
	while (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\v'
		|| *str == '\n' || *str == '\t')
	str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}	
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		rslt = rslt * 10 + (*str - '0');
		str++;
	}
	return (s * rslt);
}