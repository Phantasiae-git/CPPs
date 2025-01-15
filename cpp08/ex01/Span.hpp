/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:57 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/15 15:43:22 by phantasiae       ###   ########.fr       */
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

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();

    Span &operator=(const Span &other);
    // Other public member functions
};


#endif // SPAN_HPP