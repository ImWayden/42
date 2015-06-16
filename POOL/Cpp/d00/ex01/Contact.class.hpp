/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 16:30:44 by msarr             #+#    #+#             */
/*   Updated: 2015/06/15 16:30:47 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>

class	Contact {

	public:
		Contact(void);
		~Contact(void);
		std::string		getFirstname(void);
		std::string		getLastname(void);
		std::string		getNickname(void);
		std::string		getLogin(void);
		std::string		getPostalAddress(void);
		std::string		getEmailAddress(void);
		std::string		getPhone(void);
		std::string		getBirthDayDate(void);
		std::string		getMeel(void);
		std::string		getUnderWearColor(void);
		std::string		getDarkestSecret(void);

		void			setFirstname(std::string);
		void			setLastname(std::string);
		void			setNickname(std::string);
		void			setLogin(std::string);
		void			setPostalAddress(std::string);
		void			setEmailAddress(std::string);
		void			setPhone(std::string);
		void			setBirthdayDate(std::string);
		void			setMeel(std::string);
		void			setUnderwearColor(std::string);
		void			setDarkestSecret(std::string);
	private:
		std::string		_firstname;
		std::string		_lastname;
		std::string		_nickname;
		std::string		_login;
		std::string		_postalAddress;
		std::string		_emailAdress;
		std::string		_phone;
		std::string		_birthdayDate;
		std::string		_meel;
		std::string		_underwearColor;
		std::string		_darkestSecret;

};

#endif
