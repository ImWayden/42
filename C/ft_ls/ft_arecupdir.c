/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arecupdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 19:18:31 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 19:18:37 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lsft.h"

t_list		*ft_arecupdir(char *dir)
{
	DIR *dp;
	struct dirent *entry;
	t_list  *dirlist;
	struct stat test;
	
	dirlist = NULL;
	if ((dp = opendir(dir)) != NULL)
	{
		stat(dir ,&test);
		while ((entry = readdir(dp)))
		{
			stat(ft_strjoin(ft_strjoin(dir, "/"), entry->d_name) ,&test);
			dirlist = ft_add_list(dirlist, entry->d_name, ctime((const time_t *)&test.st_mtime));
		}
	closedir(dp);	
	}
	else
	{
		stat(dir ,&test);
		dirlist = ft_add_list(dirlist, dir, ctime((const time_t *)&test.st_mtime));		
	}
	return (dirlist);
}
