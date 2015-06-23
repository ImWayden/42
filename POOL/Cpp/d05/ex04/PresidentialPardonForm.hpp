/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:34:01 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:34:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_H
#define PresidentialPardonForm_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

    PresidentialPardonForm(std::string target);

    ~PresidentialPardonForm(void);

    void execute(const Bureaucrat &executor) const;


private:
    PresidentialPardonForm(void);

};

#endif