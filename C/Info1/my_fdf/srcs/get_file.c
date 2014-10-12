/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 16:54:09 by msarr             #+#    #+#             */
/*   Updated: 2014/10/11 22:52:00 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_get_file(char *file, t_list **list)
{
	int			fd;
	t_list		*lst;
	int			i;
	char		*str;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while ((get_next_line(fd, &str)))
		{
			ft_putendl(str);
			if ((lst = (t_list *)malloc(sizeof(t_list))))
			{
				lst->content = str;
				lst->content_size = ft_strlen(str);
				lst->next = *list;
				*list = lst;
				str = NULL;
				i++;
			}
		}
	}
	return (i);
}

static int		ft_get_tab(t_list **list, t_coord **tab, int i)
{
	int			j;
	char		**str;
	int			k;

	while (*list)
	{
		j = 0;
		k = 0;
		str = ft_strsplit((*list)->content, ' ');
		while (str[k])
			k++;
		tab[i] = (t_coord *)malloc(sizeof(t_coord) * (k + 1));
		tab[i][k].z = -2;
		while (str[j])
		{
			tab[i][j].x = j;
			tab[i][j].y = i;
			tab[i][j].z = ft_atoi(str[j]);
			j++;
		}
		*list = (*list)->next;
		i--;
	}
	return (k);
}

int				init(t_env *env)
{
	int			i;
	int			j;
	int			pad;
	t_list		*list;
	t_coord		**tab;

	list = NULL;
	i = ft_get_file(env->file, &list);
	if ((tab = (t_coord **)malloc(sizeof(t_coord *) * (i + 1))))
	{
		tab[i] = NULL;
		j = ft_get_tab(&list, tab, i - 1);
		if (j < 100)
			pad = 20;
		else
			pad = 5;
		env->x = j;
		env->y = i;
		env->pad = pad;
		transform(tab, pad, j * pad, i);
		env->tab = tab;
	}
	return (0);
}
