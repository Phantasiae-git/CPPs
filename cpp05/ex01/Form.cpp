/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:51:36 by phanta            #+#    #+#             */
/*   Updated: 2024/09/29 17:15:05 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), is_signed(0), grade_s(150), grade_e(150)
{
	std::cout<<"Form default constructor called"<<std::endl;
}

Form::Form(const std::string name, const int grade_s, const int grade_e) : name(name), grade_s(grade_s), grade_e(grade_e)
{
	std::cout<<"Form constructor called"<<std::endl;
	if(grade_s>150 || grade_e>150)
		throw GradeTooLowException();
	if(grade_s<1 || grade_e<1)
		throw GradeTooHighException();
	this->is_signed=0;
}

Form::Form(const Form &other) : name(other.name), grade_s(other.grade_s), grade_e(other.grade_e)
{
	std::cout<<"Form copy constructor called"<<std::endl;
}

Form::~Form()
{
	std::cout<<"Form destructor called"<<std::endl;
}

Form &Form::operator=(const Form &other)
{
	this->is_signed=other.is_signed;
	return *this;
}


std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->is_signed;
}

int Form::getGradeS() const
{
	return this->grade_s;
}

int Form::getGradeE() const
{
	return this->grade_e;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os<<form.getName()<<", grade to sign: "<<form.getGradeS()<<", grade to execute: "<<form.getGradeE();
	if(form.getIsSigned())
		os<<", is signed."<<std::endl;
	else
		os<<", is not signed."<<std::endl;
	return(os);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade()>this->grade_s)
		throw GradeTooLowException();
	else
		this->is_signed=1;
}