/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 21:29:44 by msarr             #+#    #+#             */
/*   Updated: 2014/11/16 21:29:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	s_setenv2(t_env **envs, char *name, char **arg, t_env *envc)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * 3);
	str[0] = ft_strdup(name);
	str[1] = ft_strdup(arg[0]);
	str[2] = NULL;
	if (!envc)
		*envs = env_listnew(str);
	else
		envc->next = env_listnew(str);
	return (1);
}

int			s_setenv(t_env **envs, char *name, char **arg)
{
	t_env			*envc;
	char			**args;

	envc = *envs;
	args = arg;
	if (args && args[0])
	{
		while (envc && envc->next && ft_strcmp(envc->name, name))
			envc = envc->next;
		if (envc && !ft_strcmp(envc->name, name))
		{
			ft_memdel((void **)&envc->arg);
			envc->arg = ft_strdup(args[0]);
		}
		else
			s_setenv2(envs, name, arg, envc);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int			cd_needed(t_shell *shell, t_tree *tree, char **pwd, char **home)
{
	*pwd = get_env(shell->env, "PWD");
	if (!*pwd)
	{
		ft_putmsg(CD_PWD, NULL);
		return (EXIT_FAILURE);
	}
	*home = get_env(shell->env, "HOME");
	if (!*home && (!tree->argv[1] || tree->argv[1][0] == '~'))
	{
		ft_putmsg(CD_HOME, NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
