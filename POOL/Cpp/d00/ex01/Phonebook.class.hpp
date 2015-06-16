/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 10:19:05 by msarr             #+#    #+#             */
/*   Updated: 2015/06/16 10:19:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"

class Phonebook {

	public:
		Phonebook();
		~Phonebook();
		void			addContact(void);
		void			searchContact(void);
		void			showContact(void);

	private:
		static int 		i;
		static Contact	book[8];
};

#endif