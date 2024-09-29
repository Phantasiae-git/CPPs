/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:51:22 by phanta            #+#    #+#             */
/*   Updated: 2024/09/29 19:59:34 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool	is_signed;
	const int grade_s;
	const int grade_e;
public:
	AForm();
	AForm(const std::string name, const int grade_s, const int grade_e);
	AForm(const AForm &other);
	~AForm();

	AForm &operator=(const AForm &other);

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
	void execute(Bureaucrat const & executor) const;
	virtual void	actually_execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);


#endif