/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 14:22:03 by msarr             #+#    #+#             */
/*   Updated: 2014/02/09 14:22:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell3.h"

void	init(char ***path, char ***cmd, char **envc)
{
	char		*str;
	static t_list		*list = NULL;

	list = ft_addlist(list, "\0");
	write(1, "$>", 2);
	str = ft_edit(list);
	list->str = ft_strjoin(list->str, str);
	*path = get_env(envc, "PATH");
	str = ft_strtrim(str);
	*cmd = ft_strsplit(str, ';');
	ft_memdel((void **)&str);
}

void	process(char **path, char **cmd, char **envc)
{
	int			i;
	pid_t		process;

	process = fork();
	i = 0;
	if (process > 0)
		wait(NULL);
	if (process == 0)
	{
		while (path[i])
		{
			execve(ft_strjoin(ft_strjoin(path[i], "/"), cmd[0]), cmd, envc);
			i++;
		}
		print_err(cmd[0], "command not found");
		exit(1);
	}
	if (process == -1)
		print_err(cmd[0], "Fork error : retry !");
}

int 	builtin_verif(char *str)
{
	if (ft_strnequ(str, "exit", ft_strlen(str)) == 1)
		return(1);
	if (ft_strnequ(str, "env", ft_strlen(str)) == 1)
		return(2);
	if (ft_strnequ(str, "cd", ft_strlen(str)) == 1)
		return(3);
	if (ft_strnequ(str, "unsetenv", ft_strlen(str)) == 1)
		return(4);
	else
		return (0);
}

char	**cp_env(char **env)
{
	int		i;
	char	**envc;

	i = 0;
	envc = (char **)malloc(sizeof(env));
	while (env[i] && env)
	{
		envc[i] = ft_strdup(env[i]);
		i++;
	}
	return (envc);
}

int		ft_is(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
