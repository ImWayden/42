/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 13:11:54 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 13:11:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "bsq.h"

t_list				*addlist(t_list *list, int i, int j)
{
	t_list			*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->i = i;
	tmp->j = j;
	tmp->next = list;
	return (tmp);
}

char 			**tab_alloc(int len)
{
	char		**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	return (tab);
}

static int		verif(char *str, char *tab, t_list **list, int l)
{
	int			i;
	int			j;
	static int	k = 0;

	i = 0;
	if (!k)
		k = ft_strlen(str);
	j = ft_strlen(tab);
	if (ft_strlen(str) == k)
	{
		while (str[i] && (str[i] == tab[j - 1] || str[i] == tab[j - 2] || str[i] == '.'))
		{
			if (str[i] == tab[j - 2])
				*list = addlist(*list, l, i);
			i++;
		}
		if (i == k)
			return (1);
	}
	return (0);
}

static char			**ft_read(char *file, t_list **list)
{
	int				fd;
	int				i;
	int				ret;
	char			*str;
	char			**tab;

	i = -1;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		str = NULL;
		while ((ret = get_next_line(fd, &str)))
		{
			if (i == -1 && (ret = ft_atoi(str)))
				tab = tab_alloc(ret + 1);
			i++;
			if (i == 0 || (i > 0 && verif(str, tab[0], list, i - 1)))
				tab[i] = str;
			else
				return (NULL);
			str = NULL;
		}
	}
	close(fd);
	return (tab);
}



char				**parser(char *file, t_list **list)
{
	return (ft_read(file, list));
}