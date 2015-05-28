/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:20:34 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/25 11:35:58 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_hashb(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i])
		result = result + str[i];
	result = result % 100;
	return (result);
}
