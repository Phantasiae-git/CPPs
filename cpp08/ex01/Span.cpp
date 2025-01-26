/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:44:33 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/26 19:38:31 by phantasiae       ###   ########.fr       */
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
}

Span::Span(const Span &other) : N(other.N), elements(other.elements)       
{
    std::cout << "Span copy constructor called" << std::endl;
    span = std::vector<int>(N);
    for(unsigned int i=0;i<elements;i++)
        span[i]=other.span[i];
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
        span=other.span;
    }
    return *this;
}

void Span::addNumber(int a)
{
    if(elements+1>N)
        throw SpanFull();
    elements++;
    span.push_back(a);
}

unsigned int absolute(int a)
{
    if(a<0)
        return -(a);
    else
        return a;
}

unsigned int Span::shortestSpan()
{
    unsigned int longest=4294967295;
    
    if(elements<2)
    {
        //throw exception
    }
    for(unsigned int i=0;i<elements;i++)
        for(unsigned int j=0;j<elements;j++)
            if(i!=j)
                if(absolute(span[i]-span[j])<(longest))
                    longest=absolute(span[i]-span[j]);
    return absolute(longest);
}

unsigned int Span::longestSpan()
{
    int longest=0;
    
    if(elements<2)
    {
        //throw exception
    }
    
    for(unsigned int i=0;i<elements;i++)
        for(unsigned int j=0;j<elements;j++)
            if((span[i]-span[j])>longest)
                longest=span[i]-span[j];
    
    unsigned int final;

    if(longest<0)
        final=-(longest);
    else
        final=longest;
    return final;
}

void  Span::printSpan()
{
    for(unsigned int i=0;i<this->elements;i++)
        std::cout << span[i] << std::endl;
}

const char *Span::SpanFull::what() const throw()
{
	return ("Can't add more numbers");
}
