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

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell2.h"

int		get_next_line(int const fd, char **line)
{
	static t_getline	sd;

	if (sd.fd == 1)
	{
		ft_memdel((void **)line);
		*line = ft_strnew(BUFF_SIZE);
		return (ft_nextpassage(&sd, line, fd));
	}
	else
	{
		sd.fd = fd;
		sd.i = 0;
		*line = ft_strnew(BUFF_SIZE);
		return (ft_firstpassage(&sd, line, fd));
	}
}

char	*ft_first_next(char **line)
{
   if (ft_strlen(*line))
   		return (&line[0][ft_strlen(*line)]);
   	else
   		return (*line);
}

void	ft_expand(char **line, char *tmp)
{
	if (ft_strlen(*line) >= BUFF_SIZE && !(ft_strlen(*line) % BUFF_SIZE))
	{
		*line = ft_strrealloc(line, BUFF_SIZE);
		tmp = &line[0][BUFF_SIZE];
	}
}

int		ft_firstpassage(t_getline *sd, char **line, int const fd)
{
	char	*tmp;
	int		ret;

	tmp = ft_first_next(line);
	while ((ret = read(fd, (*sd).tab, BUFF_SIZE)))
	{
		while ((*sd).tab[(*sd).i] != '\n' && ret)
		{
			ft_expand(line, tmp);
			*tmp = (*sd).tab[(*sd).i];
			(*sd).i++;
			tmp++;
			ret--;
		}
		if ((*sd).tab[(*sd).i] == '\n')
		{
			(*sd).i++;
			*tmp = '\0';
			return (1);
		}
		else
			(*sd).i = 0;
	}
	return (ret);
}

int		ft_nextpassage(t_getline *sd, char **line, int const fd)
{
	char	*tmp;

	tmp = *line;
	while ((*sd).tab[(*sd).i] != '\n' && (*sd).tab[(*sd).i])
	{
		*tmp = (*sd).tab[(*sd).i];
		(*sd).i++;
		tmp++;
	}
	if ((*sd).tab[(*sd).i] == '\n')
	{
		(*sd).i++;
		return (1);
	}
	else
	{
		(*sd).i = 0;
		return (ft_firstpassage(sd, line, fd));
	}
}
