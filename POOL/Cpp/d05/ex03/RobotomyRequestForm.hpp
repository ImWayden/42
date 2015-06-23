/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:26:30 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:26:30 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_H
#define RobotomyRequestForm_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

    RobotomyRequestForm(std::string target);

    ~RobotomyRequestForm(void);

    void execute(const Bureaucrat &executor) const;


private:
    RobotomyRequestForm(void);

};


#endif