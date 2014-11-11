/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 11:23:33 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 16:42:30 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WIN_X			1000
# define WIN_Y			1000
# define IND_MILIEU		1.0027
# define READ 			512

# define PLAN			1
# define SPHERE			2
# define CYLINDRE		3
# define CONE			4
# define PARABOLOIDE	5
# define HYPERBOLOIDE	6

# define HYPER_OPEN		-5000

# define BW_FILTER		0
# define SEPIA_FILTER	0

# define SQ(x)			((x) * (x))
# define ABS(nb)		((nb < 0) ? (-nb) : (nb))

# include "struc.h"
# include "init.h"
# include "parser.h"
# include "main.h"
# include "inter.h"
# include "trans_rot.h"
# include "luminosite.h"
# include "others.h"
# include "../libft/includes/libft.h"

#endif
