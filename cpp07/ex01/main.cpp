/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:37:02 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/30 22:25:16 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int array[]= { 1, 2, 3, 4 ,5 };
    
    iter(array, 5, function<int>);

    std::string sarray[]= {"ola", "adeus", "lalala"};
    
    iter(sarray, 3, function<std::string>);

    double darray[]= { 1.1, 2.0, 3.7777, -4 ,-5.9 };
    
    iter(darray, 5, function<double>);
}