/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 13:55:12 by msarr             #+#    #+#             */
/*   Updated: 2015/06/18 13:55:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class Fixed
{
	public:
    	Fixed(void);
   		Fixed(int const raw);
    	Fixed(float const raw);
    	Fixed(Fixed const &src);
    	~Fixed(void);
    	Fixed &operator=(Fixed const &rhs);
    	float toFloat(void) const;
    	int toInt(void) const;
    	void setRawBits(int const raw);
    	int getRawBits(void) const;
	private:
	    const int fractionalbBits;
	    int rawBits;

};

std::ostream 	&operator<<(std::ostream &o, Fixed const &i);

#endif