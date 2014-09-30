/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinfos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:44 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:54:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void					ft_putinfos(struct stat test)
{
	struct passwd		*tmp;
	struct group		*tmp1;
	char				*s;

	ft_putattr(test);
	ft_putnbr((int)test.st_nlink);
	ft_putchar(' ');
	tmp = getpwuid(test.st_uid);
	ft_put_s(tmp->pw_name);
	tmp1 = getgrgid(test.st_gid);
	ft_put_s(tmp1->gr_name);
	ft_putnbr((int)test.st_size);
	ft_putchar(' ');
	if (test.st_mtime)
	{
		s = ctime((const time_t *)&test.st_mtime);
		ft_put_s(ft_strtrim(s));
	}
}
