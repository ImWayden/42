/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 10:18:58 by msarr             #+#    #+#             */
/*   Updated: 2015/06/16 10:18:58 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.class.hpp"

Phonebook::Phonebook() {
	std::cout << "WELCOME TO YOUR PHONEBOOK" << std::endl;
	return ;
}

Phonebook::~Phonebook() {
	return ;
}

void		Phonebook::addContact(void) {
	std::string		buffer;

	if (Phonebook::i <= 7) {
		std::cout << "ADD a new Contact :" << std::endl;
		std::cout << "firt name : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setFirstname(buffer);
		std::cout << "last name : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setLastname(buffer);
		std::cout << "nickname : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setNickname(buffer);
		std::cout << "login : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setLogin(buffer);
		std::cout << "postal address : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setPostalAddress(buffer);
		std::cout << "email address : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setEmailAddress(buffer);
		std::cout << "phone number : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setPhone(buffer);
		std::cout << "birthday date : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setBirthdayDate(buffer);
		std::cout << "favorite meal : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setMeel(buffer);
		std::cout << "underwear color : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setUnderwearColor(buffer);
		std::cout << "darkest secret : ";
		std::cin >> buffer;
		Phonebook::book[Phonebook::i].setDarkestSecret(buffer);
		Phonebook::i++;
	}
	else
		std::cout << "THE PHONEBOOK IS FULL" << std::endl;
}

void		Phonebook::searchContact(void) {
	int		i;

	i = 0;
	std::cout << std::setw(10);
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	while (i < Phonebook::i) {
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i;
		std::cout << "|";
		std::cout << std::setw(10);
		std::string firstname = Phonebook::book[i].getFirstname();
		if (firstname.length() > 10){
			firstname = firstname.erase(9, firstname.length() - 9);
			firstname.append(".");
		}
		std::cout << firstname;
		std::cout << "|";
		std::string lastname = Phonebook::book[i].getLastname();
		if (lastname.length() > 10){
			lastname = lastname.erase(9, lastname.length() - 9);
			lastname.append(".");
		}
		std::cout << std::setw(10);
		std::cout << lastname;
		std::cout << "|";
		std::cout << std::setw(10);
		std::string nickname = Phonebook::book[i].getNickname();
		if (nickname.length() > 10){
			nickname = nickname.erase(9, nickname.length() - 9);
			nickname.append(".");
		}
		std::cout << nickname;
		i++;
		std::cout << "|" << std::endl;
		this->showContact();
	}
}


void		Phonebook::showContact(void) {
	int		index;

	std::cout << "Give the index of the contact you want to see" << std::endl;
	std::cin >> index;
	if (std::cin.good() && index >= 0 && index < Phonebook::i)
	{
		std::cout << Phonebook::book[index].getFirstname() << std::endl;
		std::cout << Phonebook::book[index].getLastname() << std::endl;
		std::cout << Phonebook::book[index].getNickname() << std::endl;
		std::cout << Phonebook::book[index].getLogin() << std::endl;
		std::cout << Phonebook::book[index].getPostalAddress() << std::endl;
		std::cout << Phonebook::book[index].getEmailAddress() << std::endl;
		std::cout << Phonebook::book[index].getPhone() << std::endl;
		std::cout << Phonebook::book[index].getBirthDayDate() << std::endl;
		std::cout << Phonebook::book[index].getMeel() << std::endl;
		std::cout << Phonebook::book[index].getUnderWearColor() << std::endl;
		std::cout << Phonebook::book[index].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cin.clear();
		std::cout << "Sorry, no match" << std::endl;
	}
}

int 		Phonebook::i = 0;
Contact 	Phonebook::book[8];