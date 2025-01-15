/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:44:33 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/15 15:45:34 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : N(N)
{
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other) : N(other.N)
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
        // Assign other attributes
    }
    return *this;
}
