/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:49:59 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 16:58:45 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string input;
    int n;
    
    std::cout<<"How many zombies? ";
    std::cin>>n;
    
    std::cout<<"And it's an army of? ";
    std::cin>>input;

    Zombie  *horde=zombieHorde(n, input);
    
    for(int i=0;i<n;i++)
        horde[i].announce();
    delete[] horde;
}