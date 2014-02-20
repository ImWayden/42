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

#include "minishell3.h"

int		get_next_line(int const fd, char **line)
{
	return (ft_firstpassage(line, fd));
}

int		ft_firstpassage(char **line, int const fd)
{
	char	*tmp;
	int		ret;

	tmp = ft_strnew(BUFFSIZE);
	ret = read(fd, tmp, BUFFSIZE);
	*line = tmp;
	return (ret);
}
