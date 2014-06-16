/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/13 18:36:02 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

bool		is_redir_no_pipe(char *str)
{
	if (is_left_redir(str) || is_right_redir(str))
		return (TRUE);
	return (FALSE);
}

bool		is_redir(char *str)
{
	if (is_left_redir(str) || is_right_redir(str) || is_pipe(str))
		return (TRUE);
	return (FALSE);
}

bool		is_sep(char *str)
{
	if (is_and_or_or_bin(str) || is_semi_colon(str))
		return (TRUE);
	return (FALSE);
}

bool		is_redir_or_sep(char *s)
{
	if (is_left_redir(s) || is_right_redir(s) || is_sep(s) || is_pipe(s))
		return (TRUE);
	return (FALSE);
}

/*int		is_directory(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
	{
		perror("Stat");
		return (0);
	}
	if (S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}*/
