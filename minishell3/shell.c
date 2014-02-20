/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 14:13:18 by msarr             #+#    #+#             */
/*   Updated: 2014/02/09 14:13:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

char	*ft_edit(t_list *list)
{
	struct termios		term;
	char				*buffer;
	char				*str;
	int					i;

	if (ft_init(&term))
		return (NULL);
	if (ft_config(&term))
		return (NULL);
	str = ft_strdup(list->str);
	i = 0;
	while (1)
	{
		buffer = ft_put(i, str);
		list = ft_choice(buffer, list, &str, &i);
		if (!list)
		{
			ft_putstr("\n");
			break;
		}
	}
	ft_defconfig(&term);
	return (str);
}

void	shell(char **env)
{
	int			i;
	char		**path;
	char		**cmd;
	int			j;
	int			k;

	while (42)
	{
		init(&path, &cmd, env);
		i = 0;
		while (cmd[i])
		{
			if (ft_is(cmd[i], '|') || ft_is(cmd[i], '>'))
			{
				dup2(STDIN_FILENO, j);
				dup2(STDOUT_FILENO, k);
				if (ft_is(cmd[i], '|'))
					ft_pipe(cmd[i], env, path);
				if (ft_is(cmd[i], '>'))
					ft_redir(cmd[i], env, path);
				dup2(j, STDIN_FILENO);
				dup2(k, STDOUT_FILENO);
			}
			else
				ft_exec(cmd[i], env, path);
			i++;
		}
	}
}

void		ft_exec(char *cmd, char **envc, char **path)
{
	char		**cmd1;

	cmd1 = ft_strsplit(ft_strtrim(cmd), ' ');
	if (cmd1[0] && builtin_verif(cmd1[0]) == 1)
		exit(1);
	else if (cmd1[0] && builtin_verif(cmd1[0]) > 1)
	{
		if (builtin_verif(cmd1[0]) == 2)
					ft_env(envc);
		if (builtin_verif(cmd1[0]) == 3)
					ft_cd(envc, cmd1[1]);
		if (builtin_verif(cmd1[0]) == 4)
					ft_unsetenv(envc, cmd1[1]);
	}
	else if (cmd1[0])
		process(path, cmd1, envc);
}
