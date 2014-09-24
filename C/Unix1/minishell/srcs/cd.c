/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 13:29:35 by msarr             #+#    #+#             */
/*   Updated: 2014/04/27 13:29:37 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static void		ft_chdir(char *path, char **envc)
{
	if (chdir(path) == -1)
		ft_putendl("cd : No such file or directory");
	else
		ft_changepwd(envc, path);
}

void			ft_cd(char **envc, char *cmd)
{
	char		*buf;

	buf = ft_getenv(envc, "HOME");
	ft_putendl(buf);
	if (cmd)
	{
		cmd = ft_strtrim(cmd);
		if (*cmd == '~')
		{
			cmd++;
			if (cmd)
				cmd = ft_strjoin(buf, &cmd[1]);
			else
				cmd = buf;
		}
		else if (*cmd == '/')
			cmd = ft_strjoin(buf, cmd);
		else if (!ft_strcmp(cmd, "-"))
			cmd = ft_getenv(envc, "OLDPWD");
	}
	else
		cmd = buf;
	ft_chdir(cmd, envc);
}
