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

t_list				*ft_getdirlist(char *dir)
{
	dir				*dp;
	struct dirent 	*entry;
	t_list  		*dirlist;
	struct stat 	test;
	
	dirlist = NULL;
	if ((dp = opendir(dir)) != NULL)
	{
		while ((entry = readdir(dp)))
		{
			if ((entry->d_name)[0] != '.')
			{
				stat(ft_strjoin(ft_strjoin(dir, "/"), entry->d_name), &test);
				dirlist = ft_addlist(dirlist, entry->d_name, ctime((const time_t *)&test.st_mtime));
			}
		}
	}
	else
	{
		stat(dir ,&test);
		dirlist = ft_add_list(dirlist, dir, ctime((const time_t *)&test.st_mtime));		
	}
	return (dirlist);
}
