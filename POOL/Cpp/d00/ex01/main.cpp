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
#include <cstdlib>
#include "Phonebook.class.hpp"

int		main(void) {
	std::string		str;
	Phonebook		book;

	while (std::cout << "ENTER YOUR CHOICE : " && std::cin >> str) {
		if (str == "EXIT")
			std::exit(0);
		else if (str == "ADD")
			book.addContact();
		else if (str == "SEARCH")
			book.searchContact();	
		}
		return 0;
}
