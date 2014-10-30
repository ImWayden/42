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
#include "minishell2.h"

static void		join_path_and_bin(char **path, char *binary, int i)
{
	(*path)[i++] = '/';
	(*path)[i] = '\0';
	*path = ft_strjoin(*path, binary);
}

static char		*get_bin_path(char *bin, t_shell *shell)
{
	char		*path;

	path = NULL;
	if (ft_strncmp(bin, "/", 1) == 0 || ft_strncmp(bin, ".", 1) == 0)
		path = ft_strdup(bin);
	else
		path = get_full_path(get_env(shell->env, "PATH"), bin);
	if (!path || (path && access(path, F_OK) == -1))
		ft_putmsg(bin, ": Command not found.\n");
	else if (access(path, X_OK) == -1 || is_directory(path))
	{
		ft_putendl(path);
		ft_putmsg(bin, " : Permission denied.\n");
	}
	else
		return (path);
	free(path);
	return (path);
}

char			*get_full_path(char *path, char *binary)
{
	int			i;
	int			len;
	char		*full_path;

	i = 0;
	full_path = NULL;
	len = ft_strlen(path) + ft_strlen(binary) + 2;
	while (path && *path)
	{
		if (i == 0 && !(full_path = malloc(sizeof(*full_path) * len)))
			return (NULL);
		full_path[i++] = *path++;
		if (*path == ':' || *path == '\0')
		{
			join_path_and_bin(&full_path, binary, i);
			if (access(full_path, F_OK) == 0)
				return (full_path);
			ft_memdel((void **)&full_path);
			i = 0;
			if (*path == ':')
				path++;
		}
	}
	return (0);
}

int				prepare_command(t_tree *cmd, t_shell *shell)
{
	if (!is_builtin(cmd->argv[0]) &&
			!(cmd->argv[0] = get_bin_path(cmd->argv[0], shell)))
		return (EXIT_FAILURE);
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
