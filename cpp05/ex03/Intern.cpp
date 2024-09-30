/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:51:08 by phanta            #+#    #+#             */
/*   Updated: 2024/09/30 22:51:29 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp" 
#include "Bureaucrat.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this=other;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    functions functions[3] = {&createPresidentialPardonForm,&createRobotomyRequestForm,&createShrubberyCreationForm};
    for(int i=0; i<3; i++)
    {
        if(name==forms[i])
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
            return (this->*functions[i])(target);
		}
            
    }
	std::cout << "Error: that form doesn't exist. Options: presidential pardon, robotomy request, shrubbery creation" << std::endl;
    return NULL;
}