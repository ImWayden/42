/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:46:58 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 10:47:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VICTIM_H
# define VICTIM_H

#include <iostream>

class Victim
{
	public:
		Victim(std::string name);
    	Victim(const Victim &src);
    	~Victim();
    	std::string getName() const;
    	Victim &operator=(Victim const &rhs);
    	virtual void getPolymorphed() const;
    	virtual void setName(std::string name);
	protected:
    	Victim();
    	std::string name;
};

std::ostream &operator<<(std::ostream &o, const Victim &i);

#endif
