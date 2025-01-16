/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:44:33 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/16 12:33:16 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0), elements(0)
{
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : N(N), elements(0)
{
    std::cout << "Span constructor called" << std::endl;
    int array[N];
    span=array;
}

Span::Span(const Span &other) : N(other.N), elements(other.elements)
{
    std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {   N = other.N;
        elements=other.elements;
        // Assign other attributes
    }
    return *this;
}

void Span::addNumber(int a)
{
    if(elements+1>N)
        throw SpanFull();
    elements++;
    span[elements-1]=a;
}

unsigned int shortestSpan()
{
    unsigned int distance;

    
}

const char *Span::SpanFull::what() const throw()
{
	return ("Can't add more numbers");
}
