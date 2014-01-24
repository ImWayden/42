/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 15:14:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL2__H
# define	MINISHELL2__H

#include <unistd.h>

#define BUFF_SIZE 1

typedef struct s_getline
{
	int		fd;
	int		i;
	char	tab[BUFF_SIZE + 1];
}	t_getline;

void			shell(char **env);
char			*ft_strtrim(char *s);
void			ft_memdel(void **ap);
int				ft_strlen(char *str);
void			ft_putstr_fd(char *s, int fd);
void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
int				ft_strlen_ptr(char **av);
char			*ft_strrealloc(char **line, unsigned int len);
int				ft_nextpassage(t_getline *sd, char **line, int const fd);
int				ft_firstpassage(t_getline *sd, char **line, int const fd);
void			ft_putendl_fd(char *s, int fd);
int				get_next_line(int const fd, char ** line);
void			ft_expand(char **line, char *tmp);
char			*ft_strjoin(char *s1, char *s2);
void			print_err(char *cmd, char *text);
int				check_cmd(char **path, char *cmd);
char			**get_path(char **env);
char			**ft_strsplit(char *s, char c);
int		ft_strnequ(char *s1,char *s2, size_t n);
char			*ft_strsub(char *s, unsigned int start, size_t len);

#endif