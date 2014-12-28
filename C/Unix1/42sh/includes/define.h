/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:24:21 by msarr             #+#    #+#             */
/*   Updated: 2014/12/28 13:24:24 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**	KEY CODE
*/

# define K_UP(buf)			(buf[0] == 27 && buf[1] == 91 && buf[2] == 'A')
# define K_DOWN(buf)		(buf[0] == 27 && buf[1] == 91 && buf[2] == 'B')
# define K_LEFT(buf)		(buf[0] == 27 && buf[1] == 91 && buf[2] == 'D')
# define K_RIGHT(buf)		(buf[0] == 27 && buf[1] == 91 && buf[2] == 'C')
# define K_END(buf)			(buf[0] == 27 && buf[1] == 91 && buf[2] == 'F')
# define K_HOME(buf)		(buf[0] == 27 && buf[1] == 91 && buf[2] == 'H')
# define K_DEL(buf)			(buf[0] == 127 && !buf[1])
# define K_BDEL(buf)		(buf[0] == 27 && buf[1] == 91 && buf[2] == '3')

/*
**	ERROR MSG
*/

# define NAME				"42sh: "
# define USAGE				"Usage: ./42sh"
# define FORMAT				"Wrong line format"
# define DIR_E				"No such file or directory"
# define PERM				"permission denied."
# define HOME				"HOME not set."
# define PWD				"PWD NOT SET."
# define OLDPWD				"OLDPWD NOT SET."
# define STAT				"STAT error"
# define INIT				"Malloc error"
# define WAITPID			"Waitpid error"
# define CMD_E				"Invalid null command."
# define CMD_1				"command not found."
# define REDIR_E1			"Missing name for redirect."
# define REDIR_E2			"Ambiguous input redirect."
# define REDIR_E3			"Ambiguous output redirect."

# define SETENV				"setenv : "
# define READ				"Read : "
# define OPEN				"Open : "
# define ALIAS				"alias : "
# define CD					"cd : "

# define SETENV_FORMAT		SETENV FORMAT
# define ALIAS_FORMAT		ALIAS FORMAT
# define CD_DIR				CD DIR_E
# define OPEN_DIR			OPEN DIR_E
# define READ_PERM			READ PERM
# define CD_PERM			CD PERM
# define CD_HOME			CD HOME
# define CD_PWD				CD PWD
# define CD_OLDPWD			CD OLDPWD

#endif
