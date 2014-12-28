/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xleft_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 13:10:21 by msarr             #+#    #+#             */
/*   Updated: 2014/12/27 23:54:09 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "getline.h"
#include "shell.h"

void			ft_putmsg(char *name, char *msg)
{
	write(STDERR_FILENO, NAME, ft_strlen(NAME));
	write(STDERR_FILENO, name, ft_strlen(name));
	if (msg)
	{
		write(STDERR_FILENO, ": ", 3);
		write(STDERR_FILENO, msg, ft_strlen(msg));
	}
	write(STDERR_FILENO, "\n", 1);
}

int				open_file(char *name)
{
	int			fd;

	if (access(name, F_OK) == -1 || access(name, R_OK) == -1)
	{
		if (access(name, F_OK) == -1)
			ft_putmsg(name, DIR_E);
		else
			ft_putmsg(name, READ_PERM);
		return (-1);
	}
	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_putmsg(name, OPEN_DIR);
	return (fd);
}

int				spe_left(t_tree *tree, t_shell **shell)
{
	int			fd[2];
	char		**args;
	char		*str;
	char		*str1;

	(void)shell;
	args = tree->right->argv;
	if (!(str = args[0]))
		return (EXIT_FAILURE);
	if (pipe(fd) == -1)
		return (FATAL_ERROR);
	while (42)
	{
		ft_putstr("~>");
		str1 = get_line(*shell, 2);
		if (!ft_strcmp(str1, str))
			break ;
		write(fd[1], str1, ft_strlen(str1));
		write(fd[1], "\n", 1);
		ft_memdel((void **)&str1);
	}
	ft_memdel((void **)&str1);
	close(fd[1]);
	set_fd_in(tree->left, fd[0]);
	return (execute_it(tree->left, shell));
}

int				left_redirection(t_tree *tree, t_shell **shell)
{
	int			fd;
	char		**args;

	args = tree->right->argv;
	if (!args || !args[0] || (fd = open_file(args[0])) == -1)
		return (EXIT_FAILURE);
	set_fd_in(tree->left, fd);
	return (execute_it(tree->left, shell));
}
