/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:40:17 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:32:23 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int					ft_setenv(t_shell *shell)
{
	t_env			*envc;
	char			**args;

	envc = shell->env;
	args = shell->cmd;
	if (args && args[1] && args[2] && !args[3])
	{
		while (shell->env && envc)
		{
			if (!ft_strcmp(envc->name, args[1]))
			{
				ft_memdel((void **)&envc->arg);
				envc->arg = ft_strdup(args[2]);
				break;
			}
			if (!envc->next)
			{
				envc->next = env_listnew(&args[1]);
				break;
			}
			envc = envc->next;
		}
	}
	else
		ft_putendl("setenv : wrong line format.\n");
	return (1);
}
