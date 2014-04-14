/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 14:01:29 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 15:07:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		 		LSFT_H__
# define			LSFT_H__

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include "libft.h"


typedef struct		s_list
{
	char			*str;
	char			*atime;
	struct s_list	*next;
}					t_list;

t_list				*ft_addlist(t_list *list, char *str, char *atime);
void				ft_putattr(struct stat sb);
t_list				*ft_getdirlist(char *dir);
t_list				*ft_arecupdir(char *dir);
t_list				*ft_sortlist(t_list *list);
t_list				*ft_rsortlist(t_list *list);
t_list				*ft_arsortlist(t_list *list);
t_list      		*ft_asortlist(t_list *list);
void				ft_putdir(char *str);
void				ft_putinfo(t_list *list, char *dir);
void				ft_putilist(t_list *list);
void				ft_putends(const char *s);
void				ft_acceserror(char *str , char **argv, int argc);
void				ft_putinfos(struct stat test);
void				ft_listswap(t_list *tmp, t_list *tmp1);

#endif
