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

#include "libft.h"

static int			ft_recup(t_line *sd, char *str, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			ft_join(line, str);
			tmp = ft_strdup(&(str[i + 1]));
			ft_memdel((void **)&(sd->str));
			sd->str = tmp;
			return (1);
		}
		i++;
	}
	return (0);
}

static int			ft_read(t_line *sd, char **line)
{
	char			tmp[BUFF_SIZE + 1];
	int				ret;

	if (ft_recup(sd, sd->str, line))
		return (1);
	*line = sd->str;
	sd->str = NULL;
	while ((ret = read(sd->fd, tmp, BUFF_SIZE)) >= 0)
	{
		tmp[ret] = '\0';
		if (ft_recup(sd, tmp, line))
			return (1);
		if (!ret && *line && **line)
			return (1);
		else if (!ret)
			return (0);
		ft_join(line, tmp);
	}
	return (-1);
}

int					get_next_line(int const fd, char **line)
{
	static t_line	*sd = NULL;
	t_line			*tmp;

	tmp = sd;
	*line = NULL;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp && (tmp = (t_line *)malloc(sizeof(t_line))))
	{
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = sd;
		sd = tmp;
	}
	else if (!tmp)
		return (-1);
	return (ft_read(tmp, line));
}
