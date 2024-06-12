/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:24 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 11:08:21 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout<<"Cat default constructor called"<<std::endl;
    this->type="Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    std::cout<<"Cat copy constructor called"<<std::endl;
    this->brain=new Brain(*cat.brain);
}

Cat &Cat::operator=(const Cat &cat)
{
    Animal::operator=(cat);
	this->brain=new Brain(*cat.brain);
    return(*this);
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout<<"Meow"<<std::endl;
}