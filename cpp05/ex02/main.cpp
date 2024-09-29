/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:37:19 by phanta            #+#    #+#             */
/*   Updated: 2024/09/29 17:20:04 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat ze("ze", 2);
        std::cout<<ze<<std::endl;
		
        Form zeForm("ze", 3, 1);
        std::cout<<zeForm<<std::endl;
        
		Form zeForm2= Form();
		std::cout<<zeForm2<<std::endl;
		
        ze.SignForm(zeForm2);

        ze.decrementGrade();
        std::cout<<ze<<std::endl;

        ze.decrementGrade();
        std::cout<<ze<<std::endl;

        ze.SignForm(zeForm);
        std::cout<<zeForm<<std::endl;

		zeForm=zeForm2;
		std::cout<<zeForm<<std::endl;

		Form zeForm3("ze3", 4, 1);
std::cout<<zeForm3<<std::endl;

		zeForm3.beSigned(ze);
		std::cout<<zeForm3<<std::endl;

    } catch (std::exception &e)
    {
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }
}
