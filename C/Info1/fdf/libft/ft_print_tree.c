/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:26:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/15 15:58:33 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		print_tree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		print_tree(tree->left);
	ft_putstr("data = "),
	ft_putstr(tree->data);
	ft_putstr("\n");
	if (tree->right)
		print_tree(tree->right);
}
