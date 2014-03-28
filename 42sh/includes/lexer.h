/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:29:41 by msarr             #+#    #+#             */
/*   Updated: 2014/03/27 10:29:44 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H_
# define PARSER_H_

typedef enum			s_tokenid
{
	TOK_NONE,
	TOK_AND,	 // &&
	TOK_SEPAND,	 // &
	TOK_OR,	 // ||
	TOK_PIPE,	 // |
	TOK_SEP,	 // ;
	TOK_LPAREN,	 // (
	TOK_RPAREN,	 // )
	TOK_DLESS,	 // <<
	TOK_LESS,	 // <
	TOK_DGREAT,	 // >>
	TOK_GREAT,	 // >
	TOK_WORD	 // all others
} 						t_tokenid;

typedef struct	 		s_node
{
	s_tokenid	 		id;
	struct s_node		left;
	struct s_node		right;
}						s_token;

typedef struct			t_quote
{
	const char	 		*start;
	const size_t		lenstart;
	const char	 		*stop;
	const size_t	 	lenstop;
} 						s_quote;


#endif
