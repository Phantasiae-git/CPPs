/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:57:14 by phanta            #+#    #+#             */
/*   Updated: 2024/09/29 17:15:31 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("normal"), grade(150)
{
    std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    std::cout<<"Bureaucrat constructor called"<<std::endl;
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade)
{
    std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this != &bureaucrat)
        this->grade=bureaucrat.grade;
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat destructor called"<<std::endl;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low");
}

std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void Bureaucrat::setGrade(int grade1)
{
    if(grade1<1)
        throw GradeTooHighException();
    else if(grade1>150)
        throw GradeTooLowException();
    else
        this->grade=grade1;
}

void Bureaucrat::incrementGrade()
{
	setGrade((this->grade)-1);
}

void Bureaucrat::decrementGrade()
{
	setGrade((this->grade)+1);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade()<<std::endl;
	return(os);
}