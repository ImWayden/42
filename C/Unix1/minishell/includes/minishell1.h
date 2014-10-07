/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 15:14:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL1_H
# define	MINISHELL1_H

# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>
# include <sys/stat.h>
# include "libft.h"

# define BUFFSIZE 1000

typedef struct		s_env
{
	char			*name;
	char			*arg;
	char			**cmd;
	struct s_env 	*next;
}					t_env;

typedef struct 		t_shell
{
	t_env			*env;
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
int						ft_setenv(t_shell *shell);
int						ft_unsetenv(t_shell *shell);
char					*get_env(t_env *env, char *str);
int						cd(t_shell *shell, t_tree *tree);
int						builtins_center(t_shell *shell);

#endif