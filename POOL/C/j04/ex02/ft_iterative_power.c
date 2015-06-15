/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 13:30:58 by msarr             #+#    #+#             */
/*   Updated: 2014/07/08 13:31:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_iterative_power(int nb, int power)
{
	int			rslt;

	rslt = 1;
	if (power < 0)
		return (0);
	while (power)
	{
		rslt = rslt * nb;
		power--;
	}
	return (rslt);
}
