/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 13:32:10 by msarr             #+#    #+#             */
/*   Updated: 2014/07/08 13:32:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	else if (index == 1 || index == 2)
		return (1);
	else if (index == 3)
		return (2);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
