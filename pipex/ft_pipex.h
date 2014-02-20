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
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);
int				ft_father(char **argv, char **str, int fd, int tube[2]);
int				ft_son(char **argv, char **str, int fd, int tube[2]);
char			*ft_strjoin(char *s1, char *s2);

#endif