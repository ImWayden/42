/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:26:16 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:26:16 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5) {
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    std::cout << "<" << this->getName() << "> has been pardoned by Zafod Beeblebrox." << std::endl;
    (void) executor;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}