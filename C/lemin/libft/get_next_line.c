/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:32:20 by msarr             #+#    #+#             */
/*   Updated: 2014/03/04 13:34:51 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int						ft_is(char *str, int c)
{
	int					i;

	i = 0;
	while (str && *str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (0);
}

static t_getline		*ft_search(t_getline *list, int fd, char **line)
{
	t_getline			*tmp;

	tmp = list;
	while (tmp && tmp->next && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp && tmp->fd == fd)
	{
		*line = tmp->str;
		return (tmp);
	}
	else
		return (NULL);
}

int		readstr(t_getline *sd, char **line)
{
	char	*tmp;
	char	*tmp1;
	int		ret;

	tmp = ft_strnew(BUFF_SIZE);
	while (sd && (ret = read(sd->fd, tmp, BUFF_SIZE)))
	{
		if (!ret)
			return (0);
		if ((ret = ft_is(tmp, '\n')))
		{
			tmp[ret] = '\0';
			tmp1 = *line;
			*line = ft_strjoin(*line, tmp);
			ft_memdel((void **)&tmp1);
			tmp1 = sd->str;;
			sd->str = ft_strjoin(sd->str, &(tmp[ret + 1]));
			ft_memdel((void **)&tmp1);
			tmp[ret] = '\n';
			ft_memdel((void **)&tmp);
			return (1);
		}
		else
			*line = ft_strjoin(*line, tmp);
		ft_memdel((void **)&tmp);
	}
	return (ret);
}

int		first(t_getline *sd, char **line)
{
	char	*tmp;
	int		ret;
	int		i;

	if (sd && sd->str && (ret = ft_is(sd->str, '\n')))
	{
		i = ft_strlen(sd->str);
		*line = ft_strsub(sd->str , 0, ret);
		i = i - ft_strlen(*line);
		tmp = sd->str;
		sd->str = ft_strsub(sd->str, ret + 1, i);
		ft_memdel((void **)&tmp);
		return (1);
	}
	else if (sd && sd->str)
	{
		*line = ft_strdup(sd->str);
		ft_memdel((void **)&(sd->str));
	}
	return (readstr(sd, line));
}

int						getnextline(int const fd, char **line)
{
	static t_getline	*sd = NULL;
	t_getline			*tmp;

	tmp = ft_search(sd, fd, line);
	if (tmp)
		return (first(tmp, line));
	else
		sd = ft_addlist(sd, NULL, fd);
	return (first(sd, line));
}
