/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcut.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 00:19:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 04:55:49 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

/*
** Lists and Structures
*/

typedef enum			e_bool
{
	FAUX = 0, VRAI = 1
}						t_bool;

typedef struct			s_termlist
{
	char				*str;
	struct s_termlist	*prev;
	struct s_termlist	*next;
}						t_termlist;

typedef struct			s_env
{
	char				*name;
	char				*arg;
	struct s_env		*next;
}						t_env;

typedef struct			s_lex
{
	char				*str;
	struct s_lex		*next;
	struct s_lex		*prev;
}						t_lex;

typedef struct			s_tree
{
	int					ope;
	int					fd[2];
	char				**argv;
	struct s_tree		*left;
	struct s_tree		*right;
	struct s_tree		*next;
}						t_tree;

typedef struct			s_alias
{
	char				*name;
	char				*arg;
	struct s_alias		*next;
	struct s_alias		*prev;
}						t_alias;

typedef struct			s_shell
{
	char				*prompt;
	char				*pwd;
	char				*a_file;
	char				*h_file;
	char				**path;
	t_tree				*tree;
	t_line				*hist;
	t_alias				*alias;
	char				**envc;
	t_env				*env;
	int					flag;
	int					son;
}						t_shell;

#endif
