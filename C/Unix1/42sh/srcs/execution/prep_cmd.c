/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:09:30 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 13:09:32 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "shell.h"

char			*get_full_path(char **path, char *binary)
{
	int			i;
	char		*str;
	char		*full_path;

	i = 0;
	full_path = NULL;
	while (path && path[i])
	{
		str = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(str, binary);
		ft_memdel((void **)&str);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		ft_memdel((void **)&full_path);
		i++;
	}
	return (NULL);
}

static char		*get_bin_path(char *bin, t_shell *shell)
{
	char		*path;

	path = NULL;
	if (ft_strncmp(bin, "/", 1) == 0 || ft_strncmp(bin, ".", 1) == 0)
		path = ft_strdup(bin);
	else
		path = get_full_path(shell->path, bin);
	if (!path || (path && access(path, F_OK) == -1))
		ft_putmsg(bin, CMD_1);
	else if (access(path, X_OK) == -1)
		ft_putmsg(path, PERM);
	else
		return (path);
	ft_memdel((void **)&path);
	return (path);
}

int				prepare_command(t_tree *cmd, t_shell *shell)
{
	char		*str;

	if (!is_builtin(cmd->argv[0]))
	{
		if ((str = get_bin_path(cmd->argv[0], shell)))
		{
			ft_memdel((void **)&cmd->argv[0]);
			cmd->argv[0] = str;
		}
		else
			return (EXIT_FAILURE);
	}
	return (0);
}

int				prepare_all_commands(t_tree *tree, t_shell *shell)
{
	int			flag;

	if (tree && (tree->ope == IS_CMD))
	{
		if ((flag = prepare_command(tree, shell)) != EXIT_SUCCESS)
			return (flag);
	}
	else if (tree)
	{
		if ((flag = prepare_all_commands(tree->right, shell)) != EXIT_SUCCESS)
			return (flag);
		if ((flag = prepare_all_commands(tree->left, shell)) != EXIT_SUCCESS)
			return (flag);
	}
	return (EXIT_SUCCESS);
}
