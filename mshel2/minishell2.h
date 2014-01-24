/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:35:09 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/24 01:08:45 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL2_H
# define MINISHELL2_H

# include <signal.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_env
{
	char	**environ;
	char	**tabPath;
	char	*line;
	char	*path;
}				t_env;

int		main(int ac, char **av, char **envp);
void	print_err(char *cmd, char *text);
int		ft_strlen_ptr(char **av);
void	get_path(t_env *env);
int		check_cmd(t_env *env, char *cmd);

#endif /* !MINISHELL2 */
