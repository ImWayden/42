/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:21:18 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 16:09:16 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		INTER_H
# define	INTER_H

double		inter_plan(t_utils utils, t_objet *obj);
double		inter_cylindre(t_utils utils, t_objet *obj);
double		inter_cone(t_utils utils, t_objet *obj);
double		inter_sphere(t_utils utils, t_objet *obj);
double		inter_paraboloide(t_utils utils, t_objet *obj);
double		inter_hyperboloide(t_utils utils, t_objet *obj);
double		search_res(double a, double b, double d);
double		delta(double a, double b, double c);

#endif
