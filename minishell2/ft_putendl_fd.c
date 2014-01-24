/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:29:16 by msarr             #+#    #+#             */
/*   Updated: 2013/11/21 15:29:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell2.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
		write(fd, tmp++, 1);
	write(fd, "\n", 1);
}
