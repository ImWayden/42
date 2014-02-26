/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:49:39 by sraccah           #+#    #+#             */
/*   Updated: 2014/01/23 23:18:08 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./includes/libft.h"

int			ft_open(char *str, int args)
{
	int		fd;

	fd = open(str, args);
	if (fd == -1)
		ft_exit("Error : could not open\n");
	return (fd);
}