/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:29:55 by msarr             #+#    #+#             */
/*   Updated: 2015/06/24 15:29:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Base_Class_H
#define Base_Class_H

class Base {

public:
    Base();

    Base(Base &src);

    virtual ~Base();

    Base &operator=(Base &src);
};

#endif
