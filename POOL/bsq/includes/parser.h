/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 14:12:48 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 14:12:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					PARSER_H
# define				PARSER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "bsq.h"

# define BUFF_SIZE 1200

typedef struct			s_getline
{
	int					fd;
	char				*str;
	struct s_getline	*next;
}						t_getline;

int						ft_strlen(char *str);
int						ft_atoi(char *str);
char					**parser(char *file, t_list **list);
char					*ft_strnew(size_t size);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strsub(char *s, unsigned int start, size_t len);
int						get_next_line(int fd, char **line);

#endif
