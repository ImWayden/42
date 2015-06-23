/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:26:25 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:26:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45) {

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    std::srand(time(NULL));

    if (rand() % 2 == 0) {
        std::cout << "<" << this->getName() << "> has been robotomized." << std::endl;
    }
    else {
        std::cout << "<" << this->getName() << "> has not been robotomized, system failure." << std::endl;
    }
    (void) executor;
}


RobotomyRequestForm::~RobotomyRequestForm() {

}