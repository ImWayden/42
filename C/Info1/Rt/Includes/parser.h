/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:23:25 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 16:29:53 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	PARSER_H
# define	PARSER_H

int			get_scene(t_param *param, char *file);
int			check_limit_while(char **tab, int *i);
char		*extract_str(char *str);
char		*get_next_line(const int fd);
void		assign_value(t_objet **elem, char *str);
void		put_spot_in_list(t_spot **spot, t_spot elem);
void		assign_value_spot(t_spot **elem, char *str);
void		put_obj_in_list(t_objet **obj, t_objet elem);
void		get_eye(t_param *param, char **tab, int *i);
void		get_general(t_param *param, char **tab, int *i);
t_param		*get_all_obj(t_param *param, char **tab);
t_spot		*get_one_spot(t_spot *spot, char **tab, int *i);
t_spot		*extract_elem_spot(t_spot *elem, char **tab, int *i);
t_objet		*get_elem(t_objet *elem, char **tab, int *i);
t_objet		*get_one_obj(t_objet *obj, char **tab, int *i);
t_objet		*get_elem_obj(t_objet *elem, char **tab, int *i, int flag);

#endif
