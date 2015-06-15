/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 15:32:27 by msarr             #+#    #+#             */
/*   Updated: 2015/06/15 15:32:29 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	maj(char c) {
	return ((c >= 'a' && c <= 'z') ? c - 32 : c);
}

int		main(int ac, char **av) {
	int	i;
	int	j;
	
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		j = 1;
		while (j < ac) {
			i = -1;
			while (av[j][++i])
				std::cout << maj(av[j][i]);
			j++;
		}
		std::cout << std::endl;
	}
	return 0;
}
