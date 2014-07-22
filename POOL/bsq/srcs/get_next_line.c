/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:32:20 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 20:15:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int				ft_is(char *str, int c)
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
	return (-1);
}

static t_getline		*ft_search(t_getline *list, int fd, char **line)
{
	t_getline			*tmp;

	tmp = list;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp && tmp->fd == fd)
	{
		*line = tmp->str;
		return (tmp);
	}
	else
		return (NULL);
}

static int				first(t_getline *sd, char **line)
{
	char				*tmp;
	int					ret;

	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(sd->fd, tmp, BUFF_SIZE)) > 0)
	{
		if ((ret = ft_is(tmp, '\n')) >= 0)
		{
			tmp[ret] = '\0';
			*line = ft_strjoin(*line, tmp);
			sd->str = ft_strjoin(sd->str, &(tmp[ret + 1]));
			tmp[ret] = '\n';
			return (1);
		}
		else
			*line = ft_strjoin(*line, tmp);
	}
	return (ret);
}

static int				next(t_getline *sd, char **line)
{
	int					i;
	int					ret;

	if (sd->str && (ret = ft_is(sd->str, '\n')) >= 0)
	{
		i = ft_strlen(sd->str);
		*line = ft_strsub(sd->str, 0, ret);
		i = i - ft_strlen(*line);
		sd->str = ft_strsub(sd->str, ret + 1, i);
		return (1);
	}
	else if (sd->str)
	{
		*line = sd->str;
		sd->str = NULL;
	}
	return (first(sd, line));
}

int						get_next_line(int const fd, char **line)
{
	static t_getline	*sd = NULL;
	t_getline			*tmp;

	tmp = ft_search(sd, fd, line);
	if (tmp)
		return (next(tmp, line));
	else
	{
		tmp = (t_getline *)malloc(sizeof(t_getline));
		if (tmp)
		{
			tmp->fd = fd;
			tmp->str = NULL;
			tmp->next = sd;
			sd = tmp;
		}
	}
	return (first(sd, line));
}
