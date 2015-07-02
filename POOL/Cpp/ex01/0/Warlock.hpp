/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 13:35:19 by msarr             #+#    #+#             */
/*   Updated: 2015/06/26 13:35:22 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>

class Warlock
{
	private:
		Warlock(Warlock &);
		Warlock(void);
		Warlock & operator=(Warlock &);

		std::string	name;
		std::string	title;

	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string		getName(void) const;
		std::string		getTitle(void) const;
		void			setTitle(std::string );
		void			introduce(void) const;
	
};

#endif
