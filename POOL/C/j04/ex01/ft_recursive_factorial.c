/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 13:30:34 by msarr             #+#    #+#             */
/*   Updated: 2014/07/08 13:30:37 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else
		return (n * ft_recursive_factorial(n - 1));
}
