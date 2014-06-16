/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/16 17:34:35 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRAMMAR_H
# define GRAMMAR_H

# include "my_42sh.h"

/*
** Define Redirection
*/

# define LEFT_R "<"
# define RIGHT_R ">"
# define D_LEFT_R "<<"
# define D_RIGHT_R ">>"
# define PIPE "|"

/*
** Define Execution
*/

# define AND "&"
# define AND_BIN "&&"
# define OR_BIN "||"
# define SEMICOLON ";"

/*
** Data type
*/


# define IS_CMD 0
# define IS_FILE 1
# define IS_PIPE 2
# define IS_RIGHT 3
# define IS_D_RIGHT 4
# define IS_LEFT 5
# define IS_D_LEFT 6
# define IS_AND 7
# define IS_OR 8

typedef struct	 		s_lex
{
	char				*str;
	struct s_lex		*next;
	struct s_lex		*prev;
}						t_lex;


typedef struct			s_tree
{
	int					ope;
	char				**argv;
	struct s_tree		*left;
	struct s_tree		*right;
	struct s_tree		*next;
}						t_tree;

/*
** Library
*/

void			free_lex(t_lex **lex);
void			free_tree(t_tree **tree);
void			lex_delfirst(t_lex **lex);


/*
** check type
*/

bool			is_ope(char c);
bool			is_word(char *str);
bool			is_left_redir(char *);
bool			is_right_redir(char *);
bool			is_pipe(char *);
bool			is_and_or_or_bin(char *);
bool			is_semi_colon(char *);
bool			is_redir_or_sep(char *);
bool			is_redir(char *);
bool			is_sep(char *);
bool			is_redir_no_pipe(char *);
int				is_directory(char *);

/*
** check syntax
*/

t_lex			*syntax_error(char *);
int				left_redir_syntax(t_lex *lex);
int				right_redir_syntax(t_lex *lex);
int				pipe_and_or_syntax(t_lex *lex);
t_lex			*lexer(char *line);
t_lex			*addlist(t_lex *list, char *str);
void			free_lex(t_lex **lex);

/*
** parsing,c
*/

bool			alloc_tree(t_tree **, t_tree **);
t_tree			*init_tree(void);
t_tree			*make_parsing(t_lex **);
t_tree			*lexor_and_parsor(char *line);

/*
** BNF
*/

bool			expression(t_tree **, t_lex **);
bool			or_exp(t_tree **, t_lex **);
bool			and_exp(t_tree **, t_lex **);
bool			pipe_exp(t_tree **, t_lex **);
bool			redir_exp(t_tree **, t_lex **);
bool			redir_left_norm(t_tree **, t_lex **);
bool			redir_left_spe(t_tree **, t_lex **);
bool			redir_right(t_tree **, t_lex **);
bool			redir_right_norm(t_tree **, t_lex **);
bool			redir_right_spe(t_tree **, t_lex **);
bool			command_exp(t_tree **, t_lex **);
bool			cmd_exp(t_tree **, t_lex **);
bool			args_exp(t_tree **, t_lex **);
bool			file_exp(t_tree **, t_lex **);
bool			special_case(t_tree **, t_lex **);

#endif /* !MY_42SH_H */