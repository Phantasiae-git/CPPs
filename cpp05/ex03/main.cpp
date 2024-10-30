/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:37:19 by phanta            #+#    #+#             */
/*   Updated: 2024/10/08 11:28:03 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp" 
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() 
{ 
	Intern ze;
    

    AForm* form1 = ze.makeForm("presidential pardon", "ola");
	delete form1;

    AForm* form2 = ze.makeForm("robotomy request", "adeus");
delete form2;

    AForm* form3 = ze.makeForm("shrubbery creation", "ya");
	try {
        Bureaucrat ze("ze", 150);

        ze.signForm(*form3);
        ze.executeForm(*form3);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	try {
        Bureaucrat yah("yah", 145);
		Bureaucrat fixe("fixe", 137);
		Bureaucrat ze("ze", 150);
		//shrubForm.beSigned(ze);
        yah.signForm(*form3);

        yah.executeForm(*form3);
		fixe.executeForm(*form3);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

delete form3;

    AForm* form4 = ze.makeForm("unknown form", "dfrgrdfh");
delete form4;
}