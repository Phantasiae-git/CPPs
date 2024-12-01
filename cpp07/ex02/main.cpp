/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:37:02 by phantasiae        #+#    #+#             */
/*   Updated: 2024/12/01 17:15:26 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    std::cout << "----------------------------scope test:" << std::endl;
    {
        Array<int> tmp;
        tmp = numbers;
        Array<int> test(tmp);
        // for (int i = 0; i < test.size(); i++)
        // {
        //     std::cout << i << std::endl;
        //     std::cout << test[i] << std::endl;
        //     std::cout << numbers[i] << std::endl;
        // }
    }
    std::cout << "----------------------------scope test end:" << std::endl;
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
        std::cout << numbers[MAX_VAL] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << numbers[MAX_VAL-1] << std::endl;
        std::cout << mirror[MAX_VAL-1] << std::endl;
        numbers[MAX_VAL-1] = 0;
        std::cout << numbers[MAX_VAL-1] << std::endl;
        std::cout << mirror[MAX_VAL-1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    Array<int> a(2);
    Array<int> b(5);
    Array<int> c(0);
    a=b;
    a=c;
    delete [] mirror;//
    return 0;
}