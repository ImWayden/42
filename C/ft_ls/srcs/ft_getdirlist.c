/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdirlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:58:49 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:59:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

t_dirlist				*ft_getdirlist(char *dir)
{
	DIR				*dp;
	struct dirent	*entry;
	t_dirlist		*dirlist;
	struct stat		test;

	dirlist = NULL;
	if ((dp = opendir(dir)) != NULL)
	{
		while ((entry = readdir(dp)))
		{
			if ((entry->d_name)[0] != '.')
			{
				stat(ft_strjoin(ft_strjoin(dir, "/"), entry->d_name), &test);
				dirlist = ft_addlist(dirlist, entry->d_name,
							time((time_t *)&test.st_mtime));
			}
		}
	}
	return (dirlist);
}
