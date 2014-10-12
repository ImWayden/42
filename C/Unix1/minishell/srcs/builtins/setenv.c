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

	envc = shell->env;
	if (shell->cmd[1] && shell->cmd[2] && !shell->cmd[3])
	{
		while (shell->env && envc)
		{
			if (!ft_strcmp(envc->name, shell->cmd[1]))
			{
				ft_memdel((void **)&envc->arg);
				envc->arg = ft_strdup(shell->cmd[2]);
				break ;
			}
			if (!envc->next)
			{
				envc->next = env_listnew(&(shell->cmd[1]));
				break ;
			}
			envc = envc->next;
		}
	}
	else
		ft_putendl("setenv : wrong line format.");
	return (1);
}
