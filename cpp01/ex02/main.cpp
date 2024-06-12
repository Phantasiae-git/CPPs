/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:10:35 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 17:17:03 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string s = "HI THIS IS BRAIN";

    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout<<"Addresses:"<<std::endl<<"string: "<<&s<<std::endl;
    std::cout<<"Pointer: "<<stringPTR<<std::endl;
    std::cout<<"Reference: "<<&stringREF<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"Values:"<<std::endl<<"string: "<< s << std::endl;
    std::cout<<"Pointer: "<<*stringPTR<< std::endl;
    std::cout<<"Reference: "<<stringREF<< std::endl;
}