/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:21:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL1_H
# define	MINISHELL1_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft.h"

# define BUFFSIZE 1000

typedef struct		s_env
{
	char			*name;
	char			*arg;
	struct s_env 	*next;
}					t_env;

typedef struct 		t_shell
{
	t_env			*env;
	char			**cmd;
	char			**envc;
	char			**path;
	char			*prompt;
	int				flag;
}					t_shell;

/*
** builtin functions
*/

t_env					*add_env_list(t_env *list, char **str);
int						aff_env(t_shell *shell);
int						is_builtin(char *cmd);
t_env					*env_listnew(char **str);
t_env					*env_to_list(char **env);
char					**list_to_tab(t_env *env);
int						ft_setenv(t_shell *shell);
int						ft_unsetenv(t_shell *shell);
char					*get_env(t_env *env, char *str);
int						cd(t_shell *shell);
int						builtins_center(t_shell **shell);
t_shell					*init(char	**env);
void					shell(char **env);
void					exec_cmd(t_shell *shell);
void					free_env(t_env **envc);
void					free_shell(t_shell **shell);
void					env_delone(t_env **envc);
int						ft_exit(t_shell **shell);

#endif