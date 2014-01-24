/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:34:22 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/24 01:09:27 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

int		main(int ac, char **av, char **envp)
{
	t_env	env;
	pid_t	pid;
	int		ret;

	if (ac == 1)
	{
		env.environ = envp;
		get_path(&env);
		while (42)
		{
			ft_putstr("$>");
			ft_get_next_line(0, &(env.line));
			env.line = ft_strtrim(env.line);
			av = ft_strsplit(env.line, ' ');
			av[ft_strlen_ptr(av)] = NULL;
			if (ft_strequ(av[0], "exit") == 1)
				exit(1);
			if (ft_strlen(env.line) > 0)
			{
				pid = fork();
				if (pid == 0)
				{
					ret = check_cmd(&env, av[0]);
					if (ret == -1)
					{
						print_err(env.line, "command not found");
						exit(1);
					}
					else
						execve(env.path, av, envp);
					free(env.path);
				}
				else
					wait(NULL);
			}
		}
	}
	else
		ft_putstr("ft_minishell2 dont use arguments\n");
	return (0);
}
