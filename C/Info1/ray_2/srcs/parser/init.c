/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 19:03:27 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 12:34:48 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static int		init_exit()
{
	ft_putendl("unknown format");
	exit (0);
}

t_lex			*get_gen(t_env *env, t_lex *lex)
{
	while (lex)
	{
		if (!ft_strcmp(lex->str, "<EYE>") && (lex = get_cam(&env->cam, lex->next)))
			continue ;
		else if (!ft_strcmp(lex->str, "<A.A>") && (lex = lex->next))
			env->anti = get_nbr(lex->str);
		else if (!ft_strcmp(lex->str, "<AMB>") && (lex = lex->next))
			env->amb = get_nbr(lex->str);
		else
			break;
		lex = lex->next;
	}
	return (lex);
}

void			ft_init(t_env *env, char *file)
{
	t_lex		*lex;
	t_lex		*tmp;
	//t_scene		*s = NULL;
	//t_light		*l = NULL;

	lex = get_file(file);
	tmp = lex;
	env->scene = NULL;
	env->light = NULL;
	env->back_color = COLOR_BLUE;
	while (lex)
	{
		if (!ft_strcmp(lex->str, "<GEN>"))
			lex = get_gen(env, lex->next);
		else if (!ft_strcmp(lex->str, "<OBJ>"))
			lex = get_obj(env, lex->next);
		else
		{
			ft_putendl(lex->str);
			init_exit();
		}
		if (lex == tmp)
			break ;
	}
	/*l = env->light;
	while (l)
	{
		sleep(1);
		s = new_scene();
		s->type = SPHERE;
		s->pos = l->pos;
		s->color = new(1, 1, 1);
		s->size = 5;
		s->next = env->scene;
		env->scene = s;
		l = l->next;
	}*/
}