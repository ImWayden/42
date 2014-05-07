/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 20:30:23 by msarr             #+#    #+#             */
/*   Updated: 2013/12/30 20:30:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PIPEX_H
# define FT_PIPEX_H

# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int				ft_father(char **argv, char **str, int fd, int tube[2]);
int				ft_son(char **argv, char **str, int fd, int tube[2]);

#endif