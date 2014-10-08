/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:40:33 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:37:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int					ft_unsetenv(t_shell *shell)
{
	t_env			*envc;
	t_env			*tmp;
	char			*args;

	envc = shell->env;
	if ((args = (shell->cmd)[1]))
	{
		while (envc && envc->next && ft_strcmp(envc->name, args))
		{
			tmp = envc;
			envc = envc->next;
		}
		if (!ft_strcmp(envc->name, args))
		{
			tmp->next = envc->next;
			//env_delone(&envc);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
