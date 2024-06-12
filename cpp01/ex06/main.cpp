/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:15:59 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 20:01:13 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    std::string input;
    Harl harl;
    
    if (argc != 2 || !argv[1])
	{
		std::cout <<"DEBUG, INFO, WARNING or ERROR"<< std::endl;
		return(1);
	}
    std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int a=222;
    
    for (int i = 0; i < 4; i++)
    {
		if (levels[i] == argv[1])
			a=i;
    }
    
    switch (a)
	{   
		case 0:
			harl.complain("DEBUG");
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
            break;
		case 1:
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
            break;
		case 2:
            harl.complain("WARNING");
            harl.complain("ERROR");
            break;
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
            break;
	}
}