/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:03:21 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:03:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("joe", 10);
    Bureaucrat b1("joe", 140);

    try
    {
        while (42)
        {
            b.incrementGrade();
            std::cout << b << std::endl;
        }
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    };
    try
    {
        while (42)
        {
            b1.decrementGrade();
            std::cout << b1 << std::endl;
        }
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    };

    return 0;
}