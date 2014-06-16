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

#include "my_42sh.h"

t_env				*my_unsetenv(t_env **env, char *line)
{
	t_env			*envc;
	t_env			*tmp;
	char			*args;

	envc = *env;
	if (envc)
	{
		args = ft_strtrim(line);
		if (args)
		{
			while (envc && envc->next && ft_strcmp(envc->name, args))
			{
				tmp = envc;
				envc = envc->next;
			}
			if (!ft_strcmp(envc->name, args))
			{
				tmp->next = envc->next;
				env_delone(&envc);
			}
		}
		return (*env);
	}
	return (envc);
}