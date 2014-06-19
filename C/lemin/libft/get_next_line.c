/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:32:20 by msarr             #+#    #+#             */
/*   Updated: 2014/06/17 16:21:56 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int						ft_is(char *str, int c)
{
	int					i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static t_getline		*ft_search(t_getline *list, int fd)
{
	t_getline			*tmp;

	tmp = list;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp && tmp->fd == fd)
		return (tmp);
	else
		return (NULL);
}

static int				first(t_getline *sd, char **line, int *flag)
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
	if (line && *line)
	{
		*flag = -1;
		return (1);
	}
	return (ret);
}

static int				next(t_getline *sd, char **line, int *flag)
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
	return (first(sd, line, flag));
}

int						get_next_line(int const fd, char **line)
{
	static t_getline	*sd = NULL;
	t_getline			*tmp;
	static int			flag = 1;

	if (flag == -1)
		return (0);
	tmp = ft_search(sd, fd);
	if (tmp)
		return (next(tmp, line, &flag));
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
	return (first(sd, line, &flag));
}
