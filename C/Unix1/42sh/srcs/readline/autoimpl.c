/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autoimpl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 11:41:30 by msarr             #+#    #+#             */
/*   Updated: 2014/11/15 22:48:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"
#include "grammar.h"
#include "42sh.h"

void				insert(t_line *tmp2, t_line *tmp, char *str)
{
	while (tmp2)
	{
		if (ft_strcmp(str, tmp2->str) < 0)
		{
			tmp->next = tmp2;
			tmp2->prev->next = tmp;
			tmp->prev = tmp2->prev;
			tmp2->prev = tmp;
			break ;
		}
		if (!tmp2->next)
		{
			tmp2->next = tmp;
			tmp->prev = tmp2;
			break ;
		}
		tmp2 = tmp2->next;
	}
}

t_line				*addline(t_line *list, char *str)
{
	t_line			*tmp;
	t_line			*tmp2;

	tmp = (t_line *)malloc(sizeof(t_line));
	tmp->str = ft_strdup(str);
	tmp->prev = NULL;
	tmp->next = NULL;
	if (!list)
		return (tmp);
	if (ft_strcmp(str, list->str) < 0)
	{
		tmp->next = list;
		list->prev = tmp;
		list = tmp;
		return (list);
	}
	tmp2 = list;
	insert(tmp2, tmp, str);
	return (list);
}

t_line				*getlist(t_line *list, char *token, char *dir, int i)
{
	DIR				*dp;
	struct dirent	*entry;

	if (dir && (dp = opendir(token)))
	{
		while ((entry = readdir(dp)))
			if (!ft_strncmp(dir, entry->d_name, i))
				list = addline(list, entry->d_name);
		closedir(dp);
	}
	return (list);
}

char				*word(char *word, int start)
{
	int				j;

	j = 0;
	while (start >= 0 && ft_isalnum(word[start]))
	{
		start--;
		j++;
	}
	if (j)
		return (ft_strsub(word, ++start, j));
	else
		return (NULL);
}

int					autoimpl(char **str, t_shell *shell, int j)
{
	char			**path;
	t_line			*list;
	char			*tmp;
	char			*dir;
	int				i;

	list = NULL;
	path = shell->path;
	dir = get_env(shell->env, "PWD");
	i = ft_strlen(*str) - 1 - j;
	if ((tmp = word(*str, i)))
	{
		if (dir)
			list = getlist(list, dir, tmp, ft_strlen(tmp));
		while (path && *path)
			list = getlist(list, *path++, tmp, ft_strlen(tmp));
		if (list)
			setlist(&list, str, j);
	}
	return (1);
}
