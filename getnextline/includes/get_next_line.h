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

# ifndef		GETNEXTLINE__H
#define			GETNEXTLINE__H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "../includes/libft.h"


typedef struct 			s_getline
{
	int					fd;
	char				*str;
	struct s_getline 	*next;
}						t_getline;

t_getline		*ft_listnew(int i, char *str);
t_getline		*ft_addlist(t_getline *list, char *str, int i);
int				getnextline(int const fd, char **line);

#endif
