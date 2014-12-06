/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/06 02:10:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "struct.h"

/*
** Functions
*/

t_lem				*parse();
t_lem				*newlem(void);
t_room				*new_room(char *str, int x, int y);
int					hash(char *str);
int					get_door(t_lem *lem, int flag);
t_link				*new_link(t_room *room);
t_link				*link_lst(t_link *l, t_room *room);
int					way(t_room *room, t_lem *lem);
int					add_link(char *str, t_lem *lem);
int					hash(char *str);
void				lemin(t_lem *lem, t_env env);
int					get_room(char *str, t_lem *lem, int flag);
t_trans				*add_trans(t_trans *trans, t_room *src, t_room *dst);


#endif