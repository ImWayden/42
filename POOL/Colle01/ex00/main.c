/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 15:06:36 by msarr             #+#    #+#             */
/*   Updated: 2014/07/12 15:06:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putstr(char *str);
void		ft_display(char **av);
int			ft_error(int ac, char **av);
int			ft_sudoku(char **av, int i, int j);

int			main(int argc, char **argv)
{
	if (!ft_error(argc - 1, &argv[1]))
	{
		if (ft_sudoku(&argv[1], 0, 0))
			ft_display(&argv[1]);
		else
			ft_putstr("Erreur\n");
	}
	else
		ft_putstr("Erreur\n");
	return (0);
}
