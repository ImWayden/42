/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/24 23:09:36 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_42SH_H
# define MY_42SH_H

# include <stdio.h>
# include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>
/*
** Lists and Structures
*/

typedef struct 	s_env
{
	char		*path;
	char		*user;
	char		*home;
	char		*pwd;
	char		*oldpwd;
}				t_env;

/*
** ft_init
*/

void			ft_help(void);
void			ft_welcome(void);
void			ft_prompt(char **envs);

/*
** ft_get
*/

pid_t			ft_getfork(void);
void			ft_get_exit(char **av);
int				ft_check(char *buff);
char			**ft_getenv(char **envp);
void			ft_getcmd(char **av, char ***envs);

/*
** ft_builtin
*/

char			**setenv_builtin(char **envs, char *name, char *value);
char			**unsetenv_builtin(char **envs, char *name);
char			**cd_builtin(char **av, char **envs);

#endif /* !MY_42SH_H */