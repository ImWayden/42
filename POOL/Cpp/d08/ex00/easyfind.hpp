/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 17:02:59 by msarr             #+#    #+#             */
/*   Updated: 2015/06/25 17:02:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
void easyfind(T haystack, int needle) {
    if (std::find(haystack.begin(), haystack.end(), needle) == haystack.end())
        throw std::exception();
}

#endif