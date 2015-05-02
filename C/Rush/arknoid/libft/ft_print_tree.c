/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:26:00 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/25 14:57:07 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_print_tree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		ft_print_tree(tree->left);
	ft_putstr("data = "),
	ft_putstr(tree->data);
	ft_putstr("\n");
	if (tree->right)
		ft_print_tree(tree->right);
}
