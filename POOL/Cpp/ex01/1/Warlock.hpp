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
#include <list>
#include <vector>


class Warlock
{
	private:
		Warlock(Warlock &);
		Warlock(void);
		Warlock & operator=(Warlock &);

		std::string	name;
		std::list<std::string>	titles;
		std::vector<std::string>	quotes;

	public:
		Warlock(std::string name);
		~Warlock();
		std::string		getName(void) const;
		void			introduce(void) const;
		void			addTitle(std::string const & title);
		void			addQuote(std::string const & title);
		void			removeQuote(std::string const & title);
		void			removeTitle(std::string const & title);
		void			talk(void);

;	
};

#endif
