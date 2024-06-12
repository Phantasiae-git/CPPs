/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:24 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 10:22:53 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog default constructor called"<<std::endl;
    this->type="Dog";
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    std::cout<<"Dog copy constructor called"<<std::endl;
    *this=dog;
}

Dog &Dog::operator=(const Dog &dog)
{
    Animal::operator=(dog);
    return(*this);
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
}

void Dog::makeSound() const
{
    std::cout<<"Woof"<<std::endl;
}