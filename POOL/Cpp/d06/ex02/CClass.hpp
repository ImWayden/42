/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CClass.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:29:00 by msarr             #+#    #+#             */
/*   Updated: 2015/06/24 15:29:02 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_H
#define C_H

#include "baseClass.hpp"

class C : public Base {

public:
    virtual ~C();

    C();

    C(C &src);

    C &operator=(C &src);
};

#endif
