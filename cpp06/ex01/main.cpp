/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:44:43 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/27 15:33:28 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data a;
    a.n=1;
    std::cout << &a << std::endl;
    std::cout << a.n << std::endl;
    uintptr_t num;
    num=Serializer::serialize(&a);
    Data *b= Serializer::deserialize(num);
    std::cout << b << std::endl;
    std::cout << b->n << std::endl;
}