/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:37:19 by phanta            #+#    #+#             */
/*   Updated: 2024/09/30 21:38:46 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp" 
#include "Bureaucrat.hpp"

int main() 
{ 
	std::cout << "ShrubberyCreationForm" << std::endl<< std::endl;
    try {
        Bureaucrat ze("ze", 150);
        ShrubberyCreationForm shrubForm("o teu pai");

        ze.signForm(shrubForm);
        ze.executeForm(shrubForm);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat yah("yah", 145);
		Bureaucrat fixe("fixe", 137);
		Bureaucrat ze("ze", 150);
        ShrubberyCreationForm shrubForm("ali nao sei");
		//shrubForm.beSigned(ze);
        yah.signForm(shrubForm);

        yah.executeForm(shrubForm);
		fixe.executeForm(shrubForm);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl<< "RobotomyRequestForm" << std::endl<< std::endl;
    try {
        Bureaucrat ze("ze", 50);
        RobotomyRequestForm robotomyForm("Bender");

        ze.signForm(robotomyForm);
        std::cout << "Form signed by " << ze.getName() << std::endl;

        Bureaucrat ze2("ze2", 45);
		//Bureaucrat ze2("ze2", 0);
		ze.executeForm(robotomyForm);
        ze2.executeForm(robotomyForm);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl<<"PresidentialPardonForm" << std::endl<< std::endl;
    try {
        Bureaucrat aaaaaaaaaaaaaaa("aaaaaaaaaaaaaaa", 30);
        PresidentialPardonForm pardonForm("o teu pai");

        aaaaaaaaaaaaaaa.signForm(pardonForm);

        Bureaucrat frank("Frank", 5);
        frank.executeForm(pardonForm);
		frank.signForm(pardonForm);
		frank.executeForm(pardonForm);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat admin("admin", 1);
        ShrubberyCreationForm shrubForm("garden");

        admin.signForm(shrubForm);
        admin.executeForm(shrubForm);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
