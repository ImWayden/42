/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:40:17 by msarr             #+#    #+#             */
/*   Updated: 2014/06/10 14:52:04 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

int					ft_setenv(t_shell *shell, t_tree *tree)
{
	t_env			*envc;
	char			**args;

	envc = shell->env;
	args = tree->argv;
	if (!envc)
		shell->env = env_listnew(args);
	else
	{
		if (args && args[1] && args[2] && !args[3])
		{
			while (envc && envc->next && ft_strcmp(envc->name, args[1]))
				envc = envc->next;
			if (!ft_strcmp(envc->name, args[1]))
				envc->arg = ft_strdup(args[0]);
			else
				envc->next = env_listnew(args);
		}
		else
		{
			ft_putmsg("setenv", " : wrong line format.\n");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
