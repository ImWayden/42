/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 14:12:48 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 14:12:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					PARSER_H
# define				PARSER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "bsq.h"
# include "libft.h"

t_bsq					*parser(char *file);
t_bsq_list				*addlist(t_bsq_list *list, int i, int j);
int						get_next_line(int fd, char **line);

#endif
