/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:22:22 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 16:50:07 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		OTHERS_H
# define	OTHERS_H

char		**token_tab();
char		*check_error(char *str, int count, char **token);
int			get_count_of_extract(char **tab, int *i);
void		count_obj(t_param *param);
t_k			*check_k(t_k *k2, t_k *k);
t_k			*search_k(t_objet *tmp, t_utils utils, t_k *k, t_param *param);
t_utils		*init_norm(t_objet *obj, t_objet obj3, t_utils *utils);

#endif
