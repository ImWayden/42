/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:26:05 by msarr             #+#    #+#             */
/*   Updated: 2015/06/16 16:26:07 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_CLASS_H
# define PONY_CLASS_H

#include <iostream>

class Pony {

public:
    Pony(void);

    ~Pony(void);

    void speak(void);

    void setColor(std::string);

    void setName(std::string);

private:
    std::string color;
    std::string name;
};

#endif

#endif
