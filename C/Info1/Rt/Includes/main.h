/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:21:49 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 16:21:30 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MAIN_H
# define		MAIN_H

int			expose(t_param *param);
int			key(int bouton, t_param **param);
void		free_list(t_param *param);
void		rempli_img(t_param *param);
void		mlx_ppti(int x, int y, t_param *param, t_k *k);
t_k			calc(double x, double y, t_param *param, t_k *k);

#endif

