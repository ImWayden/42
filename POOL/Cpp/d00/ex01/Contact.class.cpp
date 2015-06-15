/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 17:28:19 by msarr             #+#    #+#             */
/*   Updated: 2015/06/15 17:28:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string Contact::getFirstname(void){
	return this->_firstname;
}

std::string	Contact::getLastname(void){
	return this->_lastname;
}

std::string Contact::getNickname(void){
	return this->_nickname;
}

std::string Contact::getLogin(void){
	return this->_login;
}

std::string Contact::getPostalAddress(void){
	return this->_postalAddress;
}

std::string	Contact::getEmailAddress(void){
	return this->_emailAdress;
}

std::string Contact::getPhone(void)
{
	return this->_phone;
}

std::string Contact::getBirthDayDate(void){
	return this->_birthdayDate;
}

std::string Contact::getMeel(void){
	return this->_meel;
}

std::string Contact::getUnderWearColor(void){
	return this->_underwearColor;
}

std::string Contact::getDarkestSecret(void){
	return this->_darkestSecret;
}

void		Contact::setContact(void) {
	std::string		buffer;

	std::cout << "ADD a new Contact :" << std::endl;
	std::cout << "firt name : " << std::endl;
	std::cin >> buffer;
	this->setFirstname(buffer);
	std::cout << "last name : " << std::endl;
	std::cin >> buffer;
	this->setLastname(buffer);
	std::cout << "nickname : " << std::endl;
	std::cin >> buffer;
	this->setNickname(buffer);
	std::cout << "login : " << std::endl;
	std::cin >> buffer;
	this->setLogin(buffer);
	std::cout << "postal address : " << std::endl;
	std::cin >> buffer;
	this->setPostalAddress(buffer);
	std::cout << "email address : " << std::endl;
	std::cin >> buffer;
	this->setEmailAddress(buffer);
	std::cout << "phone number : " << std::endl;
	std::cin >> buffer;
	this->setPhone(buffer);
	std::cout << "birthday date : " << std::endl;
	std::cin >> buffer;
	this->setBirthdayDate(buffer);
	std::cout << "favorite meal : " << std::endl;
	std::cin >> buffer;
	this->setMeel(buffer);
	std::cout << "underwear color : " << std::endl;
	std::cin >> buffer;
	this->setUnderwearColor(buffer);
	std::cout << "darkest secret : " << std::endl;
	std::cin >> buffer;
	this->setDarkestSecret(buffer);
}

void		Contact::setFirstname(std::string str){
	this->_firstname = str;
	return ;
}

void		Contact::setLastname(std::string str){
	this->_lastname = str;
}


void		Contact::setNickname(std::string str){
	this->_nickname = str;
}


void		Contact::setLogin(std::string str){
	this->_login = str;
}

void		Contact::setPostalAddress(std::string str){
	this->_postalAddress = str;
}

void		Contact::setEmailAddress(std::string str){
	this->_emailAdress = str;
}


void		Contact::setPhone(std::string str){
	this->_phone = str;
}

void		Contact::setBirthdayDate(std::string str){
	this->_birthdayDate = str;
}

void		Contact::setMeel(std::string str){
	this->_meel = str;
}

void		Contact::setUnderwearColor(std::string str){
	this->_underwearColor = str;
}

void		Contact::setDarkestSecret(std::string str){
	this->_darkestSecret = str;
}