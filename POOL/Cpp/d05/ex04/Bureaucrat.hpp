/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:33:18 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:33:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "Form.hpp"
#include <iostream>

class Bureaucrat {

public:

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    Bureaucrat(std::string name, short grade);

    Bureaucrat(Bureaucrat &src);

    ~Bureaucrat(void);

    void incrementGrade();

    void decrementGrade();

    void signForm(Form &src);

    std::string getName(void);

    Bureaucrat &operator=(Bureaucrat &src);

    void executeForm(Form const &form);

    short getGrade(void) const;

private:

    const std::string name;
    short grade;

    Bureaucrat(void);

};

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs);

#else
class Bureaucrat;
#endif