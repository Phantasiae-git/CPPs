/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:53:12 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/27 15:47:13 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this=other;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
    return(*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t a=reinterpret_cast<uintptr_t>(ptr);
    return(a);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *a=reinterpret_cast<Data *>(raw);
    return(a);
}
