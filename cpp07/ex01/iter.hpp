/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:36:55 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/30 22:25:09 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void function(T &item)
{
    std::cout << item << " passed through the function" << std::endl;
}

template <typename T>
void iter(T *array, int length, void (function)(T &))
{
    for(int i=0;i<length; i++)
        (function)(array[i]);
}

#endif