/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_rot.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:24:02 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 16:48:53 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TRANS_ROT_H
# define	TRANS_ROT_H

int			obj_rot(t_utils *utils, t_objet *list, int sens, int flag);
void		trans_obj(t_objet *obj, t_vect *pos);
void		trans_inv(t_utils *utils, t_objet *obj, int flag);
void		trans_nor(t_utils *utils, t_objet *obj, int flag);
void		obj_rotate(t_objet *obj3, t_objet *obj, int flag);
void		rotate_x(double *x, double *y, double *z, double a);
void		rotate_y(double *x, double *y, double *z, double a);
void		rotate_z(double *x, double *y, double *z, double a);
t_utils		*rot_eye(t_utils *utils);
t_utils		*rot_pos(t_utils *utils, t_objet *list, int flag);
t_utils		*rot_spot(t_utils *utils, t_objet *list, int flag);
t_utils		*rot_vector(t_utils *utils, t_objet *list, int flag);
t_utils		*norm_rotate(t_utils *utils, t_objet *list, int flag);

#endif
