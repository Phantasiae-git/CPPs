/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:44:43 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/26 19:11:21 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try{
        Span a(3);
        a.printSpan();
        a.addNumber(2);
        a.addNumber(4);
        a.addNumber(8);
        std::cout << a.longestSpan() << std::endl;
        std::cout << a.shortestSpan() << std::endl;
        a.printSpan();
    }catch(std::exception &e){
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }
}