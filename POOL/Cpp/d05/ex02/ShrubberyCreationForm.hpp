/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:24:10 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:24:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_H
#define ShrubberyCreationForm_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

    ShrubberyCreationForm(std::string target);

    ~ShrubberyCreationForm(void);

    void execute(const Bureaucrat &executor) const;


private:
    ShrubberyCreationForm(void);

};


#endif