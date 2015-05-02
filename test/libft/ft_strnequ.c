/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/25 16:56:40 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int	eq;

	if (ft_strncmp(s1, s2, n) == 0)
		eq = 1;
	else
		eq = 0;
	return (eq);
}
