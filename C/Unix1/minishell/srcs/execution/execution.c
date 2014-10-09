/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:30:21 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 19:02:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char			*get_full_path(char **path, char *binary)
{
	int			i;
	char		*str;
	char		*full_path;

	i = 0;
	full_path = NULL;
	while (path && path[i])
	{
		str = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(str, binary);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		ft_memdel((void **)&full_path);
		ft_memdel((void **)&str);
		i++;
	}
	return (NULL);
}

static char		*get_bin_path(char *bin, t_shell *shell)
{
	char		*path;

	path = NULL;
	if (ft_strncmp(bin, "/", 1) == 0 || ft_strncmp(bin, ".", 1) == 0)
		path = ft_strdup(bin);
	else
		path = get_full_path(shell->path, bin);
	if (!path || (path && access(path, F_OK) == -1))
	{
		ft_putstr(bin);
		ft_putstr(": Command not found.\n");
	}
	else if (access(path, X_OK) == -1)
	{
		ft_putstr(path);
		ft_putstr(" : Permission denied.\n");
	}
	else
		return (path);
	ft_memdel((void **)&path);
	return (path);
}

void			exec_cmd(t_shell *shell)
{
	pid_t		process;
	char		*path;

	process = fork();
	path = NULL;
	if (process > 0)
	{
		wait(NULL);
		ft_memdel((void **)&path);
	}
	if (process == 0)
	{
		if ((path = get_bin_path((shell->cmd)[0], shell)))
			execve(path, shell->cmd, shell->envc);
		exit(0);
	}
	if (process == -1)
		ft_putendl("Fork error : retry !");
}
