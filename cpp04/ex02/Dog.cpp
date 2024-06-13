/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:24 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 11:08:29 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog default constructor called"<<std::endl;
    this->type="Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *(this->brain)=*(dog.brain);
}

Dog &Dog::operator=(const Dog &dog)
{
    Animal::operator=(dog);
	*(this->brain)=*(dog.brain);
    return(*this);
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout<<"Woof"<<std::endl;
}

Brain	*Dog::getBrain() const
{
	return(this->brain);
}