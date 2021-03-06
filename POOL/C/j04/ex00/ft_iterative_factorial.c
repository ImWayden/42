/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 13:30:07 by msarr             #+#    #+#             */
/*   Updated: 2014/07/08 13:30:09 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_iterative_factorial(int nb)
{
	int			i;
	int			rslt;

	i = 1;
	rslt = 1;
	if (nb <= 0)
		return (0);
	while (i <= nb)
	{
		rslt = rslt * i;
		i++;
	}
	return (rslt);
}
