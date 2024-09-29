/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:51:22 by phanta            #+#    #+#             */
/*   Updated: 2024/09/29 17:05:53 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool	is_signed;
	const int grade_s;
	const int grade_e;
public:
	Form();
	Form(const std::string name, const int grade_s, const int grade_e);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeS() const;
	int getGradeE() const;

	 class GradeTooHighException:public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException:public std::exception
    {
    public:
        const char* what() const throw();
    };

	void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif