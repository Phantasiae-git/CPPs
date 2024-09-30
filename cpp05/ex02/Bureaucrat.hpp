/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:35:55 by phanta            #+#    #+#             */
/*   Updated: 2024/09/30 19:19:50 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

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

    std::string getName() const;
    int getGrade() const;
    void setGrade(int grade);

    void	incrementGrade();
	void	decrementGrade();

	void	signForm(AForm &form);
	void	executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif