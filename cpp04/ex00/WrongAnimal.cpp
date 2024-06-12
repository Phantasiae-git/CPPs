/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:31:17 by phanta            #+#    #+#             */
/*   Updated: 2024/06/11 11:59:45 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout<<"WrongAnimal default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
    *this=wronganimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
    this->type=wronganimal.type;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called"<<std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout<<"WrongAnimal makeSound() called"<<std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return(this->type);
}

