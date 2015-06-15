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

t_bsq_list				*addlist(t_bsq_list *list, int i, int j)
{
	t_bsq_list			*tmp;

	if ((tmp = (t_bsq_list *)malloc(sizeof(t_bsq_list))))
	{
		tmp->i = i;
		tmp->j = j;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	if (!list)
		return (tmp);
	else
	{
		tmp->prev = list->prev;
		list->prev->next = tmp;
		tmp->next = list;
		list->prev = tmp;
	}
	return (list);
}


static int		verif(char *str, t_bsq *bsq, int l)
{
	int			i;
	char		*tab;
	static int	k = 0;

	i = 0;
	if (!k)
	{
		k = ft_strlen(str);
		bsq->c_max = k;
	}
	if (ft_strlen(str) == k)
	{
		tab = bsq->str;
		while (str[i] && (str[i] == tab[0] || str[i] == tab[1] || str[i] == tab[2]))
		{
			if (str[i] == tab[1])
				bsq->list = addlist(bsq->list, l, i);
			i++;
		}
		if (i == k)
			return (1);
	}
	return (0);
}

static int			ft_recup(char *str, t_bsq *bsq)
{
	int			i;
	char		c;

	if ((i = ft_strlen(str)) >= 4)
	{
		c = str[i - 3];
		str[i - 3] = '\0';
		if ((bsq->l_max = ft_atoi(str)))
		{
			str[i - 3] = c;
			bsq->str = ft_strdup(&(str[i - 3]));
			return (1);
		}

	}
	return (0);
}

static int			ft_read(char *file, t_bsq *bsq)
{
	int				fd;
	int				i;
	int				k;
	char			*str;

	i = 0;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		str = NULL;
		while ((get_next_line(fd, &str)) && ft_strlen(str))
		{
			k = i;
			if (i == 0 && ft_recup(str, bsq))
				i++;
			else if (i > 0 && verif(str, bsq, i - 1))
				i++;
			if (k == i)
				return (0);
		}
	}
	close(fd);
	return (1);
}



t_bsq				*parser(char *file)
{
	t_bsq			*bsq;

	if ((bsq = (t_bsq *)malloc(sizeof(t_bsq))))
	{
		bsq->list = NULL;
		bsq->str = NULL;
		if (ft_read(file, bsq))
			return (bsq);
	}
	return (NULL);
}