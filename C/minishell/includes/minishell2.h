/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 15:14:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL2__H
# define	MINISHELL2__H

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <fcntl.h>
#include <term.h>
#include "libft.h"

#define BUFFSIZE 1000

void			ft_changepwd(char **envc, char *pwd);
int				ft_is(char *str, int c);
void			shell(char **env);
void			ft_env(char **env);
int				ft_isenv(char **env, char *str);
char			**ft_unsetenv(char **env, char *str);
void			ft_cd(char **env, char *path);
char			*ft_strrealloc(char **line, unsigned int len);
int				check_cmd(char **path, char *cmd);
char			**get_env(char **env, char *str);
void			ft_exec(char *cmd, char **envc, char **path);
char			*ft_getenv(char **env, char *str);

#endif