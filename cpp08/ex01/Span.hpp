/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:57 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/26 18:34:58 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>

class Span
{
private:
    std::vector<int> span;
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
    void printSpan();

    class SpanFull:public std::exception
    {
    public:
        const char* what() const throw();
    };
};


#endif // SPAN_HPP