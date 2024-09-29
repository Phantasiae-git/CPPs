/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:37:19 by phanta            #+#    #+#             */
/*   Updated: 2024/09/29 16:56:18 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat ze("ze", 2);
        std::cout<<ze<<std::endl;
        
        ze.incrementGrade();
        std::cout<<ze<<std::endl;

        ze.incrementGrade();
        std::cout<<ze<<std::endl;

    } catch (std::exception &e)
    {
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }

try {
        Bureaucrat ze("ze", 149);
		Bureaucrat ze2("ze2", 3);
        std::cout<<ze<<std::endl;
        
		ze2=ze;
		
std::cout<<ze2<<std::endl;
		
        ze.incrementGrade();
        std::cout<<ze<<std::endl;

        ze.decrementGrade();
        std::cout<<ze<<std::endl;

        ze.decrementGrade();
        std::cout<<ze<<std::endl;

        ze.decrementGrade();
        std::cout<<ze<<std::endl;

    } catch (std::exception &e)
    {
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }
}
