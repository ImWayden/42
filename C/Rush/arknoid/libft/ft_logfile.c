/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:08:24 by sraccah           #+#    #+#             */
/*   Updated: 2015/04/24 14:02:06 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_logfile(char *file, void *towrite, int mode)
{
	int		fd;

	fd = open(file, O_CREAT | O_RDWR | O_APPEND, S_IRUSR
				| S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		ft_print_red("KO !");
		return (0);
	}
	else
	{
		if (mode == 1)
			ft_putnbr_fd((int)towrite, fd);
		else if (mode == 2)
			ft_putchar_fd((char)towrite, fd);
		else if (mode == 3)
			ft_putstr_fd((char *)towrite, fd);
		else
		{
			ft_print_red("KO !");
			return (0);
		}
		return (1);
	}
	close(fd);
}
