/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 20:02:52 by msarr             #+#    #+#             */
/*   Updated: 2014/12/23 21:32:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static int		nbr_exit()
{
	ft_putendl("wrong number format");
	exit (0);
}

static double		nbr1(char *str, int *j)
{
	double			nbr;
	double			s;

	*j = 1;
	nbr = 0;
	s = 1.0;
	while (str[*j] && str[*j] != '.')
	{
		if (str[*j] == '-')
			s = -1.0;
		else if (ft_isdigit(str[*j]))
			nbr = nbr * 10 + str[*j] - '0';
		else if (str[*j] == '>')
			break ;
		else
			nbr_exit();
		*j += 1;
	}
	return (nbr * s);
}

static double		nbr2(char *str, double nbr, int *j)
{
	double			i;

	while (str[*j] && str[*j] != '>')
		(*j)++;
	(*j)--;
	i = 10;
	while (str[*j] != '>')
	{
		if (ft_isdigit(str[*j]))
		{
			nbr = (nbr * i + str[*j] - '0') / i;
			i *= 10;
		}
		else if (str[*j] == '.')
			break;
		else
			nbr_exit();
		*j -= 1;
	}
	return (nbr);
}

double			get_nbr(char *str)
{
	int			i;
	int			j;
	double		nbr;

	i = ft_strlen(str) - 1;
	nbr = 0;
	if (str[0] != '<' || str[i] != '>')
		nbr_exit(1);
	nbr = nbr1(str, &j);
	if (str[j] == '.')
		nbr = nbr2(str, nbr, &j);
	return (nbr);
}
