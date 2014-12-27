/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:40:33 by msarr             #+#    #+#             */
/*   Updated: 2014/06/10 14:15:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void			del_env(t_env *envc, t_env *tmp, t_shell *shell)
{
	if (envc == shell->env)
		shell->env = envc->next;
	else
		tmp->next = envc->next;
}

int					ft_unsetenv(t_shell *shell, t_tree *tree)
{
	t_env			*envc;
	t_env			*tmp;
	char			*args;

	envc = shell->env;
	if (envc)
	{
		args = (tree->argv)[1];
		if (args)
		{
			while (envc && envc->next && ft_strcmp(envc->name, args))
			{
				tmp = envc;
				envc = envc->next;
			}
			if (!ft_strcmp(envc->name, args))
			{
				del_env(envc, tmp, shell);
				env_delone(&envc);
				return (EXIT_SUCCESS);
			}
		}
	}
	return (EXIT_FAILURE);
}
