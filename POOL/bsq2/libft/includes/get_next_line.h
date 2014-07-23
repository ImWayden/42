/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:42:23 by msarr             #+#    #+#             */
/*   Updated: 2014/06/17 01:22:59 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					GET_NEXT_LINE_H
# define				GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct			s_getline
{
	int					fd;
	char				*str;
	struct s_getline	*next;
}						t_getline;

int						get_next_line(int const fd, char **line);
int						ft_is(char *str, int c);

#endif
