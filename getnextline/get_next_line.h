/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:42:23 by msarr             #+#    #+#             */
/*   Updated: 2013/12/02 17:42:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef		__GET_NEXT_LINE__H__
#define			__GET_NEXT_LINE__H__

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1000000


typedef struct s_getline
{
	int		fd;
	int		i;
	char	tab[BUFF_SIZE + 1];
}	t_getline;

int		ft_nextpassage(t_getline *sd, char **line, int const fd);
int		ft_firstpassage(t_getline *sd, char **line, int const fd);
int		get_next_line(int const fd, char ** line);
void	ft_expand(char **line, char *tmp);

#endif
