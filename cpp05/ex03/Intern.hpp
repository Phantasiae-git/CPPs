/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:40:09 by phanta            #+#    #+#             */
/*   Updated: 2024/09/30 22:46:44 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
private:
AForm* createPresidentialPardonForm(const std::string& target);
AForm* createRobotomyRequestForm(const std::string& target);
AForm* createShrubberyCreationForm(const std::string& target);
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern &operator=(const Intern &other);
	// Other public member functions

	AForm *makeForm(const std::string name, const std::string target);
};

typedef AForm* (Intern::*functions)(const std::string& target);

#endif