/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:29:16 by msarr             #+#    #+#             */
/*   Updated: 2014/03/02 19:27:07 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	char	*tmp;

	tmp = (char *) s;
	while (*tmp)
		write(fd, tmp++, 1);
	ft_putchar_fd('\n',fd);
}
