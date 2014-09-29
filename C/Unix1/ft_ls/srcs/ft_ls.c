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

static void			ft_putdir(char *str, int infos, struct stat test)
{
	if (infos)
		ft_putinfos(test);
	ft_putendl(str);
}

static void			ft_rls(char *str, char *str1, t_dir *dir, struct stat test)
{
	if (dir->recursive && (S_ISDIR(test.st_mode)))
	{
		ft_putdir(str, dir->infos, test);
		ft_ls(str, dir, test);
	}
	else
		ft_putdir(str1, dir->infos, test);
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

void				ft_ls(char *line, t_dir *dir, struct stat dirstat)
{
	t_dirlist		*list;
	struct stat		test;
	char			*str;

	if ((list = ft_getdirlist(line, dir->hiden)))
	{
		list = ft_sortlist(&list, dir->sort_type, dir->sort_mod);
		line = ft_strjoin(line, "/");
		while (list)
		{
			str = ft_strjoin(line, list->str);
			if (!stat(str, &test) && ft_strcmp(list->str, ".")
				&& ft_strcmp(list->str, ".."))
				ft_rls(str, list->str, dir, test);
			else if (!ft_strcmp(list->str, ".") || !ft_strcmp(list->str, ".."))
				ft_putdir(list->str, dir->infos, test);
			else
				perror(str);
			list = ft_delelmt(list);
		}
	}
	else if (S_ISDIR(dirstat.st_mode))
		perror(line);
	else
		ft_putdir(line, dir->infos, dirstat);
}
