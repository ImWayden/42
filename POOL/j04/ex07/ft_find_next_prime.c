/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 13:35:31 by msarr             #+#    #+#             */
/*   Updated: 2014/07/08 13:35:33 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_is_prime(int nb)
{
	int			i;

	if (nb == 0 || nb == 1)
		return (0);
	i = 2;
	while ((i * i) <= nb)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}

int				ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	else
		return (ft_find_next_prime(nb++));
}
