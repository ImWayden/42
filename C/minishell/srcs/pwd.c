/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:27:01 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:27:07 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

void	ft_changepwd(char **envc, char *pwd)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_getenv(envc, "PWD");
	while (envc && envc[i])
	{
		if (ft_strnequ("PWD=", envc[i], 4) == 1)
			envc[i] = ft_strjoin("PWD=", pwd);
		else if (ft_strnequ("OLDPWD=", envc[i], 7) == 1)
			envc[i] = ft_strjoin("OLDPWD=", str);
		i++;
	}
}
