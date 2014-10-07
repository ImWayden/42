/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:30:21 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:30:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static char		*ft_access(t_shell *shell)
{
	char		*str;
	struct stat	tmp;
	int			i;

	i = 0;
	if (shell->cmd && shell->cmd[0])
	{
		if (shell->cmd[0][0] == '/' || shell->cmd[0][0] == '.')
			if (stat(cmd, &tmp))
				return (0);
		else
	while (path && path[i])
	{
		str = ft_strjoin(ft_strjoin(path[i], "/"), cmd);
		if (!stat(str, &tmp))
		{
			ft_memdel((void **)&shell->cmd[0]);
			shell->cmd[0] = str;
			break;
		}
		ft_memdel((void **)&str);
		i++;
	}
	return (1);
}

static	void	exec_cmd(t_shel *shell)
{
	pid_t		process;

	process = fork();
	if (process > 0)
		wait(NULL);
	if (process == 0)
	{
		if ((ft_access(shell)))
			execv(shell->cmd[0], shell->cmd);
		exit(0);
	}
	if (process == -1)
		ft_putendl("Fork error : retry !");
}

void			shell(char **env)
{
	char		*cmd;
	char		*cmd1;
	t_shell		*shell;

	shell = init(env);
	while (shell)
	{
		ft_putstr(shell->prompt);
		get_next_line(0, &cmd);
		shell->cmd = ft_strsplit(cmd, ' ');
		ft_exec(shell);
		ft_memdel((void **)&cmd);
	}
}
