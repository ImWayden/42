/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 11:27:36 by msarr             #+#    #+#             */
/*   Updated: 2013/12/17 11:27:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct		s_lex
{
	char			*name;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;

int					ft_printf(char *str, ...);
t_lex				*lexer(char *line);
void				dell_list(t_lex **lex);
int					ft_changebase(char **str, size_t i, size_t base, int len);

#endif
