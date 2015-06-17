/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:04:21 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 13:04:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H

#include "Brain.hpp"

class Human
{
	public:
    	Human(void);
	    ~Human(void);
	    Brain&		getBrain(void);
	    std::string identify(void);
	private:
    	Brain const brain;

};

#endif