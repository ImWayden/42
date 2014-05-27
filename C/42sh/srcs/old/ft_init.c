/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:04:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/24 23:07:35 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_42sh.h"
=======
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:04:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/23 18:56:27 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"
>>>>>>> fc382db9c32f12bfa015c589a3e35834beacc415

static char			*ft_get_line(char **envs, char *name)
{
	int				i;
	char			*line;

	i = 0;
	while (envs[i])
	{
		if (ft_strstr(envs[i], name))
		{
			line = ft_strdup(envs[i]);
			line = ft_strsub(line, ft_strlen(name), ft_strlen(line));
			return (line);
		}
		i++;
	}
	return (NULL);
}

static t_env		ft_env_init(char **envs)
{
	t_env			senv;

	senv.home = ft_get_line(envs, "HOME=");
	senv.user = ft_get_line(envs, "USER=");
	senv.path = ft_get_line(envs, "PATH=");
	senv.pwd = ft_get_line(envs, "PWD=");
	senv.oldpwd = ft_get_line(envs, "OLDPWD=");
	return (senv);
}

void				ft_prompt(char **envs)
{
	t_env			senv;
	char			*pwd;

	senv = ft_env_init(envs);
	ft_print_pnobs(senv.user);
	ft_print_bnobs("~");
	pwd = ft_strsub(senv.pwd, ft_strlen(senv.home), ft_strlen(senv.pwd));
	ft_print_bnobs(pwd);
	ft_print_bnobs("~>");
}

void				ft_help(void)
{
	ft_print_red("Hi, you seems to need some help...");
	ft_putstr("First thing first...the builtins available are :\n");
	ft_print_gnobs("cd");
	ft_putstr(" : Allow you to move in all directories.\n");
	ft_print_gnobs("env");
	ft_putstr(" : To check environment variable.\n");
	ft_print_gnobs("setenv");
	ft_putstr(" : Allow you to set up environment variable.\n");
	ft_print_gnobs("unsetenv");
	ft_putstr(" : Allow you to unset the environment variable you've set.\n");
	ft_print_gnobs("exit");
	ft_putstr(" : Allow you to exit the program.\n");
	ft_print_gnobs("More...");
	ft_putstr("every basics command you are used to should work.\n");
}

void				ft_welcome(void)
{
	ft_print_red("                  => Stouf SH <=");
	ft_print_green("Welcome in my hood...please type 'help' for more info.");
}