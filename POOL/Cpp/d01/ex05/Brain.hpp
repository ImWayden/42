/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 12:59:02 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 12:59:02 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

class Brain
{
	public:
	    Brain(void);
	    ~Brain(void);
    	std::string identify();
    private:
    	int IQ;
    	int weight;
};

#endif