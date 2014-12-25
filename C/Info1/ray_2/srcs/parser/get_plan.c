/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 18:13:13 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 18:30:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

/*
typedef struct 		s_scene
{
    int 		type;
	t_vect		vect;
	double		size;
    t_vect 		color;
    double 		reflect;
    double		spec;
    double 		noise;
    struct s_scene 	*next;
}
*/

static int		plan_exit()
{
	ft_putendl("plan needs 7 args");
	exit (0);
}

t_lex			*get_plan(t_scene *scene, t_lex *lex)
{
	int			i;

	i = 0;
	scene->type = PLAN;
	while (lex)
	{
		i++;
		if (!ft_strcmp(lex->str, "<POS>") && (lex = get_pos(&scene->pos, lex)))
			continue ;
		else if (!ft_strcmp(lex->str, "<ROT>") && (lex = get_pos(&scene->dir, lex)))
			continue ;
		else if (!ft_strcmp(lex->str, "<COL>") && (lex = get_pos(&scene->color, lex)))
			continue ;
		else if (!ft_strcmp(lex->str, "<BRILL>") && (lex = lex->next))
			scene->reflect = get_nbr(lex->str);
		else if (!ft_strcmp(lex->str, "<SPEC>") && (lex = lex->next))
			scene->spec = get_nbr(lex->str);
		else if (!ft_strcmp(lex->str, "<NOISE>") && (lex = lex->next))
			scene->noise = get_nbr(lex->str);
		else if (!ft_strcmp(lex->str, "<SIZE>") && (lex = lex->next))
			scene->size = get_nbr(lex->str);
		else if (!ft_strcmp(lex->str, "<DIFF>") && (lex = lex->next))
			scene->diff = get_nbr(lex->str);
		else
			break ;
		lex = lex->next;
	}
	if (i < 7)
		plan_exit();
	return (lex);
}
