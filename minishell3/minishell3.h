/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 15:14:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL3__H
# define	MINISHELL3__H

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <fcntl.h>
#include <term.h>

#define BUFFSIZE 1000

typedef struct		s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

void			ft_putstr(char *str);
int				ft_isprint(int c);
int				ft_init(struct termios *term);
int				ft_config(struct termios *term);
int				ft_defconfig(struct termios *term);
char			*ft_put(int i, char *str);
char			*ft_join(char *s1, char *s2, int i);
void			init(char ***path, char ***cmd, char **envc);
void			process(char **path, char **cmd, char **envc);
int 			builtin_verif(char *str);
char			**cp_env(char **env);
char			*ft_edit(t_list *list);
void			ft_changepwd(char **envc, char *pwd);
t_list			*ft_addlist(t_list *list, char *str);
int				ft_init(struct termios *term);
int				ft_is(char *str, int c);
void			shell(char **env);
char			*ft_strtrim(char *s);
void			ft_memdel(void **ap);
int				ft_strlen(char *str);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strdup(char *s1);
void			ft_env(char **env);
int				ft_isenv(char **env, char *str);
char			**ft_unsetenv(char **env, char *str);
void			ft_cd(char **env, char *path);
void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
int				ft_strlen_ptr(char **av);
char			*ft_strrealloc(char **line, unsigned int len);
int				ft_firstpassage(char **line, int const fd);
void			ft_putendl_fd(char *s, int fd);
int				get_next_line(int const fd, char ** line);
void			ft_expand(char **line, char *tmp);
char			*ft_strjoin(char *s1, char *s2);
void			print_err(char *cmd, char *text);
int				check_cmd(char **path, char *cmd);
char			**get_env(char **env, char *str);
char			**ft_strsplit(char *s, char c);
int				ft_strnequ(char *s1,char *s2, size_t n);
char			*ft_strsub(char *s, unsigned int start, size_t len);
void			ft_pipe(char *cmd, char **envc, char **path);
void			ft_exec(char *cmd, char **envc, char **path);
void			ft_redir(char *cmd, char **envc, char **path);
t_list			*ft_choice(char *buffer, t_list *list, char **str, int *i);

#endif