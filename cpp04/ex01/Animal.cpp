/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:31:17 by phanta            #+#    #+#             */
/*   Updated: 2024/06/11 12:20:45 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout<<"Animal copy constructor called"<<std::endl;
    *this=animal;
}

Animal &Animal::operator=(const Animal &animal)
{
    this->type=animal.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called"<<std::endl;
}

void Animal::makeSound(void) const
{
	std::cout<<"Animal makeSound() called"<<std::endl;
}

std::string Animal::getType(void) const
{
	return(this->type);
}

