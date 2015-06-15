/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 13:31:29 by msarr             #+#    #+#             */
/*   Updated: 2014/07/08 13:31:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (!power)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb * (ft_recursive_power(nb, (power - 1))));
}
