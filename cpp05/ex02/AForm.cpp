/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:51:36 by phanta            #+#    #+#             */
/*   Updated: 2024/09/29 20:10:35 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), is_signed(0), grade_s(150), grade_e(150)
{
	std::cout<<"AForm default constructor called"<<std::endl;
}

AForm::AForm(const std::string name, const int grade_s, const int grade_e) : name(name), grade_s(grade_s), grade_e(grade_e)
{
	std::cout<<"AForm constructor called"<<std::endl;
	if(grade_s>150 || grade_e>150)
		throw GradeTooLowException();
	if(grade_s<1 || grade_e<1)
		throw GradeTooHighException();
	this->is_signed=0;
}

AForm::AForm(const AForm &other) : name(other.name), grade_s(other.grade_s), grade_e(other.grade_e)
{
	std::cout<<"AForm copy constructor called"<<std::endl;
}

AForm::~AForm()
{
	std::cout<<"AForm destructor called"<<std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	this->is_signed=other.is_signed;
	return *this;
}


std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->is_signed;
}

int AForm::getGradeS() const
{
	return this->grade_s;
}

int AForm::getGradeE() const
{
	return this->grade_e;
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os<<AForm.getName()<<", grade to sign: "<<AForm.getGradeS()<<", grade to execute: "<<AForm.getGradeE();
	if(AForm.getIsSigned())
		os<<", is signed."<<std::endl;
	else
		os<<", is not signed."<<std::endl;
	return(os);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade()>this->grade_s)
		throw GradeTooLowException();
	else
		this->is_signed=1;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if(!(this->is_signed))
	
}