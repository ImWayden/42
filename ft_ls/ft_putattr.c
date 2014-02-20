/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putattr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:56:31 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:44:37 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void	ft_putattr(struct stat sb)
{
	ft_putstr((S_ISDIR(sb.st_mode)) ? "d" : "-" );
	ft_putstr((sb.st_mode & S_IRUSR) ? "r" : "-" );
	ft_putstr((sb.st_mode & S_IWUSR) ? "w" : "-" );
	ft_putstr((sb.st_mode & S_IXUSR) ? "x" : "-" );
	ft_putstr((sb.st_mode & S_IRGRP) ? "r" : "-" );
	ft_putstr((sb.st_mode & S_IWGRP) ? "w" : "-" );
	ft_putstr((sb.st_mode & S_IXGRP) ? "x" : "-" );
	ft_putstr((sb.st_mode & S_IROTH) ? "r" : "-" );
	ft_putstr((sb.st_mode & S_IWOTH) ? "w" : "-" );
	ft_putstr((sb.st_mode & S_IXOTH) ? "x" : "-" );
	ft_putchar(' ');
}
