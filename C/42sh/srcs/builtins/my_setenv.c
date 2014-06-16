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

t_env				*my_setenv(t_env **env, char *line)
{
	t_env			*envc;
	char			**args;

	envc = *env;
	args = ft_strsplit(line, ' ');
	if (!envc)
		return (env_listnew(args));
	else
	{
		if (args && args[0] && args[1])
		{
			while (envc && envc->next && ft_strcmp(envc->name, args[0]))
				envc = envc->next;
			if (!ft_strcmp(envc->name, args[0]))
				envc->arg = args[0];
			else
				envc->next = env_listnew(args);
		}
		return (*env);
	}
}
