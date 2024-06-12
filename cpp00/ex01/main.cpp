/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:52:26 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 13:58:07 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    std::string input;
    
    PhoneBook book;

    while(1)
    {
        std::cout << "Please enter ADD, SEARCH, or EXIT" << std::endl;
        getline(std::cin, input);
        if(input=="ADD")
            book.add();
        else if(input=="SEARCH")
            book.search();
        else if(input=="EXIT")
        {
            std::cout << "All contacts deleted, goodbye!" << std::endl;
            return(0);
        }
        else
            std::cout << "That is not a valid input" << std::endl;
    }
    return(0);
}