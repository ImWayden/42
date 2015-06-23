/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:26:10 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:26:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_H
#define Intern_H

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern {

public:

    class NoForm : public std::exception {
        virtual const char *what() const throw();
    };

    Intern(void);

    Intern(Intern &src);

    ~Intern(void);

    Form *makeForm(std::string name, std::string target);

    Intern &operator=(Intern &src);

private:

};

std::ostream &operator<<(std::ostream &o, Intern &rhs);

#endif