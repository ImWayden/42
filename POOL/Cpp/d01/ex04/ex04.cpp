/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 12:51:15 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 12:51:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string simplestring = "HI THIS IS BRAIN";
    std::string *pointer = &simplestring;
    std::string &ref = simplestring;

    std::cout << "pointeur : " << *pointer << std::endl;
    std::cout << "Ref : " << ref << std::endl;

    return 0;
}