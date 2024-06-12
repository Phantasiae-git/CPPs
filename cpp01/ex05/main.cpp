/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:15:59 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 19:42:43 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    std::string input;
    Harl harl;
    
    while (1)
	{
		std::cout<<"🤓: ";
        getline(std::cin, input);
        harl.complain(input);
    }
}