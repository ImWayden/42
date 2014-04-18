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

static void				ft_putdir(char *str, int infos, struct stat test)
{
	if (infos)
		ft_putinfos(test);
	ft_putendl(str);
}

void					ft_ls(char *line, t_dir *dir, struct stat dirstat)
{
	t_dirlist			*list;
	struct stat			test;
	char				*str;

	if ((list = ft_getdirlist(line)))
	{
		list = ft_sortlist(&list, dir->sort_type, dir->sort_mod);
		while (list)
		{
			str = ft_strjoin(ft_strjoin(line, "/"), list->str);
			if (!stat(str, &test))
			{
				if (dir->recursive && (S_ISDIR(test.st_mode)))
					ft_ls(str, dir, test);
				else
					ft_putdir(list->str, dir->infos, test);
			}
			else
				perror(str);
			list = list->next;
		}
	}
	else
		ft_putdir(line, dir->infos, dirstat);
}
