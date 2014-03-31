/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:20:37 by msarr             #+#    #+#             */
/*   Updated: 2013/11/21 15:20:40 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(0, &str[i++], 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	char	*str;

	str = (char *) s;
	while (*str)
		write(fd, str++, 1);
}
