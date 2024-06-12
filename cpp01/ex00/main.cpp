/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:49:59 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 16:53:09 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string input;
    
    std::cout<<"What's the stack zombie name? ";
    getline(std::cin, input);
    randomChump(input);
    
    std::cout<<"What's the heap zombie name? ";
    getline(std::cin, input);
    Zombie* newzzz=newZombie(input);
    // std::cout<<"See how it still hasn't been destroyed? ";
    // getline(std::cin, input);
    delete newzzz;
}