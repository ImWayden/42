/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 12:47:05 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 12:47:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "minishell2.h"

void	shell(char **env)
{
	pid_t		process;
	char		**path;
	char		**cmd;
	int			ret;
	char		*str;

	write(1, "$>", 2);
	get_next_line(0, &str);
	path = get_path(env);
	str = ft_strtrim(str);
	cmd = ft_strsplit(str, ' ');
	//cmd[ft_strlen_ptr(cmd) - 1] = NULL;
	write(1, "a", 1);
	process = fork();
	ret = check_cmd(path, cmd[0]);
	if (process > 0)
	{
		free (*path);
		wait(NULL);
		shell(env);
	}
	if (process == 0)
	{
		if (ret == -1)
		{
			print_err(cmd[0], "command not found");
			exit(1);
		}
		else
			execve(path[0], cmd, env);
	}
	if (process == -1)
		shell(env);
}

int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		shell(env);
	else
	{
		write(1, argv[0], ft_strlen(argv[0]));
		write(1, " : need to be executed without argument.\n", 41);
	}
	return 0;
}
