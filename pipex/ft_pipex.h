/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 20:30:23 by msarr             #+#    #+#             */
/*   Updated: 2013/12/30 20:30:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1000000

typedef struct 	s_getline
{
	int			fd;
	int			i;
	char		tab[BUFF_SIZE + 1];
}				t_getline;

int				ft_strlen(char *str);
int				get_next_line(int const fd, char **line);
void			ft_expand(char **line, char *tmp);
int				ft_firstpassage(t_getline *sd, char **line, int const fd);
int				ft_nextpassage(t_getline *sd, char **line, int const fd);
char			*ft_strrealloc(char **line, unsigned int len);
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);

#endif