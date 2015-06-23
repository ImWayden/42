/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:33:31 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:33:31 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {

}

Intern::Intern(Intern &src) {
    (void) src;
}

Intern::~Intern() {

}

Form *Intern::makeForm(std::string name, std::string target) {
    if (name == "robotomy request") {
        Form *ret = new RobotomyRequestForm(target);
        std::cout << "Intern creates a <" << name << "> form " << "s.grade " << ret->getGradeSign() << ", ex.grade " << ret->getGradeExecute() << " targeted on " << target << std::endl;
        return ret;

    }
    else if (name == "presidential pardon") {
        Form *ret = new PresidentialPardonForm(target);
        std::cout << "Intern creates a <" << name << "> form " << "s.grade " << ret->getGradeSign() << ", ex.grade " << ret->getGradeExecute() << " targeted on " << target << std::endl;
        return ret;

    }
    else if (name == "shrubbery creation") {
        Form *ret = new ShrubberyCreationForm(target);
        std::cout << "Intern creates a <" << name << "> form " << "s.grade " << ret->getGradeSign() << ", ex.grade " << ret->getGradeExecute() << " targeted on " << target << std::endl;
        return ret;
    }
    else {
        throw NoForm();
    }
}

const char *Intern::NoForm::what() const throw() {
    return "Intern cannot creates the form 'coz it's not matching any Forms\n";
}