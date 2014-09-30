/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:32 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:51:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void			ft_putdir(char *str, t_dir *dir, struct stat test)
{
	if (dir->infos)
		ft_putinfos(test);
	ft_putendl(str);
}

static void			ft_rls(char *str, t_dir *dir, struct stat test)
{
	DIR 			*dp;

	if (dir->recursive && (S_ISDIR(test.st_mode)))
	{
		ft_putendl(NULL);
		if ((dp = opendir(str)))
		{
			closedir(dp);
			if (dir->infos)
				ft_putinfos(test);
			ft_putstr(str);
			ft_putendl(" :");
			ft_ls(str, dir);
		}
		else
			perror(str);
	}
}

static t_dirlist	*ft_delelmt(t_dirlist *list)
{
	t_dirlist		*list1;

	list1 = list;
	list = list->next;
	free(list1->str);
	free(list1);
	return (list);
}

static void			ft_putlist(t_dirlist *list, t_dir *dir, char *line)
{
	struct stat		test;
	char			*str;

	str = NULL;
	while (list)
	{
		str = ft_strjoin(line, list->str);
		if (!stat(str, &test))
			ft_putdir(list->str, dir, test);
		else
			perror(str);
			list = list->next;
	}
}

void				ft_ls(char *line, t_dir *dir)
{
	t_dirlist		*list;
	struct stat		test;
	char			*str;

	if ((list = ft_getdirlist(line, dir)))
	{
		list = ft_sortlist(&list, dir->sort_type, dir->sort_mod);
		line = ft_strjoin(line, "/");
		ft_putlist(list, dir, line);
		while (list)
		{
			str = ft_strjoin(line, list->str);
			if (!stat(str, &test))
			{
				if (ft_strcmp(list->str, ".") && ft_strcmp(list->str, ".."))
					ft_rls(str, dir, test);
			}
			else
				perror(str);
			list = ft_delelmt(list);
		}
	}
}
