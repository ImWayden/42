/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:51:16 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 11:51:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
# define PEON_H

#include "Victim.hpp"

class Peon : public Victim
{
	public:
    	Peon(std::string name);
    	Peon(const Peon &src);
    	Peon &operator=(Peon const &rhs);
    	~Peon();
    	virtual void getPolymorphed() const;
    private:
    	Peon();
};

#endif

