/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 17:42:55 by msarr             #+#    #+#             */
/*   Updated: 2015/06/15 17:42:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

static int i = -1;
static Contact	phonebook[8];

int		main(void) {
	std::string		str;
	int 			j;

	while (std::cout << "ENTER YOUR CHOICE : " && std::cin >> str) {
		if (str == "EXIT")
			std::exit(0);
		else if (str == "ADD" && i < 7 && i++)
			phonebook[i].setContact();
		else if (str == "ADD")
			std::cout << "THE PHONEBOOK IS FULL." << std::endl;
		else if (str == "SEARCH" && i != -1) {
			j = -1;
			while (++j < 8)
				phonebook[j].getContact();		
		}
	}
}
