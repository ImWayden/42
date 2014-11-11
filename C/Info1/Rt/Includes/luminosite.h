/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luminosite.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:21:40 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 16:49:19 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LUMINOSITE_H
# define	LUMINOSITE_H

void		init_new_color(t_k *k);
void		calc_coord(t_k *k, t_objet *obj3, t_utils *utils);
void		init_distance(t_spot *spot, t_utils *l, t_objet obj3);
void		ptb_norm(double *nx, double *ny, double *nz, t_objet obj3);
int			prod_scal(t_utils *l, t_utils *utils);
t_k			*ring(t_objet obj3, t_k *k);
t_k			*chess(t_objet obj3, t_k *k);
t_k			*texture(t_objet obj3, t_k *k, int text);
t_k			*shadow(t_param *param, t_objet *obj, t_k *k, t_utils *utils);
t_k			*luminosite(t_spot *spot, t_k *k, t_objet *obj, t_utils *utils);

#endif
