/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:47:02 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/19 17:33:16 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"rt.h"

void	init_token(char **tab)
{
	tab[0] = "<GEN>\0";
	tab[1] = "<EYE>\0";
	tab[2] = "<POS>\0";
	tab[3] = "<ROT>\0";
	tab[4] = "<A.A>\0";
	tab[5] = "<AMB>\0";
	tab[6] = "<OBJ>\0";
	tab[7] = "<PLAN>\0";
	tab[8] = "<SPHERE>\0";
	tab[9] = "<CYLINDRE>\0";
	tab[10] = "<CONE>\0";
	tab[11] = "<PARABOLOIDE>\0";
	tab[12] = "<HYPERBOLOIDE>\0";
	tab[13] = "<COL>\0";
	tab[14] = "<SIZE>\0";
	tab[15] = "<BRILL>\0";
	tab[16] = "<PERTURB>\0";
	tab[17] = "<MIDDLE>\0";
	tab[18] = "<SPOT>\0";
	tab[19] = NULL;
}

char	**token_tab(void)
{
	char	**tab;

	tab = malloc(sizeof(*tab) * 20);
	if (!tab)
		exit(0);
	init_token(tab);
	return (tab);
}
