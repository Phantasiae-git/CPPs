/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:57 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/16 12:30:11 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>

class Span
{
private:
    int *span;
    unsigned int N;
    unsigned int elements;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();

    Span &operator=(const Span &other);
    
    void addNumber(int a);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    class SpanFull:public std::exception
    {
    public:
        const char* what() const throw();
    };
};


#endif // SPAN_HPP