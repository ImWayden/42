/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/08 22:07:03 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MY_42SH_H
# define MY_42SH_H

# include <stdio.h>
# include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <fcntl.h>
#include <term.h>
# include "libft.h"

/*
** Lists and Structures
*/

typedef struct	 		s_lexlist
{
	char				*str;
	struct s_lexlist	*next;
	struct s_lexlist	*prev;
}						t_lexlist;

typedef struct			s_termlist
{
	char				*str;
	struct s_termlist	*prev;
	struct s_termlist	*next;
}						t_termlist;

typedef struct 			s_env
{
	char				*name;
	char				*arg;
	struct s_env		*next;
}						t_env;

/*
** ft_init
*/

void			ft_help(void);
void			ft_welcome(void);
void			ft_prompt(char **envs);

/*
** lexer and parser functions
*/

t_lexlist			*addlist(t_lexlist *list, char *str);

/*
** ft_get
*/

pid_t			ft_getfork(void);
void			ft_get_exit(char **av);
int				ft_check(char *buff);
char			**ft_getenv(char **envp);
void			ft_getcmd(char **av, char ***envs);

/*
** builtin functions
*/

t_env			*add_env_list(t_env *list, char **str);
void			aff_env(t_env *env);
t_env			*env_listnew(char **str);
t_env			*env_to_list(char	**env);
t_env			*my_setenv(t_env **env, char *line);
char			*get_env(t_env *env, char *str);
int				**my_unsetenv(char **envs, char *name);
int				**my_cd(char **av, char **envs);

/*
** termcaps
*/

char			*ft_del(char *s1, int n);
char			*ft_edit(t_termlist *list, char **envc);
char			*ft_put(int i, char *str, char **envs);
int				ft_init(struct termios *term);
int				ft_config(struct termios *term);
char			*ft_join(char *s1, char *s2, int i);
int				ft_defconfig(struct termios *term);
char			*ft_strnjoin(char *s1, char c, int n);
t_termlist		*ft_addlist(t_termlist *list, char *str);
t_termlist		*ft_editlist(t_termlist *list, char *str);
void			init(char ***cmd, char **envc);
t_termlist		*ft_choice(char *buffer, t_termlist *list, char **str, int *i);

#endif /* !MY_42SH_H */