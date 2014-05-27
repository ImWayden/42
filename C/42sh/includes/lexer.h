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

# include "libft.h"

typedef struct	 		s_lexlist
{
	char				*str;
	struct s_lexlist	*next;
}						t_lexlist;

#endif
