/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/11 19:38:27 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_42SH_H
# define MY_42SH_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>
# include "libft.h"
# include "grammar.h"

# define FATAL_ERROR	-3

/*
** Lists and Structures
*/

typedef enum			e_bool
{
	FAUX = 0, VRAI = 1
}						t_bool;

typedef struct			s_termlist
{
	char				*str;
	struct s_termlist	*prev;
	struct s_termlist	*next;
}						t_termlist;

typedef struct			s_env
{
	char				*name;
	char				*arg;
	struct s_env		*next;
}						t_env;

typedef struct			s_shell
{
	char				*prompt;
	t_tree				*tree;
	char				**envc;
	t_env				*env;
	int					flag;
}						t_shell;

/*
** ft_init
*/

t_shell					*init(char	**env);
int						re_init(t_shell *shell);
void					ft_prompt(char **envs);

/*
** ft_get
*/

pid_t					ft_getfork(void);
void					ft_get_exit(char **av);
int						ft_check(char *buff);
char					**ft_getenv(char **envp);
void					ft_getcmd(char **av, char ***envs);

/*
** builtin functions
*/

t_env					*add_env_list(t_env *list, char **str);
int						aff_env(t_shell *shell, t_tree *tree);
int						is_builtin(char *cmd);
t_env					*env_listnew(char **str);
t_env					*env_to_list(char **env);
int						ft_setenv(t_shell *shell, t_tree *tree);
int						ft_unsetenv(t_shell *shell, t_tree *tree);
char					*get_env(t_env *env, char *str);
int						cd(t_shell *shell, t_tree *tree);
void					env_delone(t_env **env);
void					free_env(t_env **envc);
char					**list_to_tab(t_env *env);
int						builtins_center(t_shell *shell, t_tree *tree);

/*
** execution
*/

void					set_fd_in(t_tree *begin, int fd);
void					set_fd_out(t_tree *begin, int fd);
void					close_trees_fd(t_tree *begin);
int						is_directory(char *path);
int						write_statut(int status);
void					ft_putmsg(char *name, char *msg);
int						spe_left(t_tree *tree, t_shell *st_shell);
int						left_redirection(t_tree *tree, t_shell *st_shell);
char					*get_full_path(char *path, char *binary);
void					main_execution(t_shell *st_shell);
int						execute_it(t_tree *tree, t_shell *st_shell);
int						prepare_command(t_tree *cmd, t_shell *st_shell);
int						prepare_all_commands(t_tree *tree, t_shell *st_shell);
int						execute_simple_command(t_tree *tree, t_shell *st_shell);
int						execute_last_command(t_tree *tree, t_shell *st_shell);
int						execute_pipe_start(t_tree *tree, t_shell *st_shell);
int						execution_chain(t_tree *tree, t_shell *st_shell);
int						execute_right_redir_spe(t_tree *tree,
						t_shell *st_shell);
int						execute_simple_pipe(t_tree *tree, t_shell *st_shell);
int						right_redirection(t_tree *tree, t_shell *st_shell);
void					init_first_pipe(t_tree *tree, t_shell *st_shell,
						int *fd);
void					init_first_pipe_spe(t_tree *tree, t_shell *st_shell,
						int *fd);

#endif