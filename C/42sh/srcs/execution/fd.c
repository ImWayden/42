/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:53:19 by msarr             #+#    #+#             */
/*   Updated: 2014/06/26 13:53:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "my_42sh.h"

void			set_fd_out(t_tree *begin, int fd)
{
	if (begin && begin->ope != IS_CMD)
	{
		if (begin->right->ope == IS_CMD)
			set_fd_out(begin->right, fd);
		else
			set_fd_out(begin->left, fd);
	}
	else if (begin && begin->ope == IS_CMD)
		begin->fd[1] = fd;
}

void			set_fd_in(t_tree *begin, int fd)
{
	if (begin && begin->ope != IS_CMD)
	{
		if (begin->right->ope == IS_CMD)
			set_fd_in(begin->right, fd);
		else
			set_fd_in(begin->left, fd);
	}
	else if (begin && begin->ope == IS_CMD)
		begin->fd[0] = fd;
}

void			close_trees_fd(t_tree *begin)
{
	if (begin)
	{
		if (begin->fd[0] != 0)
		{
			close(begin->fd[0]);
			begin->fd[0] = 0;
		}
		if (begin->fd[1] != 1)
		{
			close(begin->fd[0]);
			begin->fd[1] = 0;
		}
		close_trees_fd(begin->left);
		close_trees_fd(begin->right);
	}
}
