/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:45:24 by phanta            #+#    #+#             */
/*   Updated: 2024/06/11 12:09:07 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout<<"WrongCat default constructor called"<<std::endl;
    this->type="WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongcat) : WrongAnimal(wrongcat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
    this->type = wrongcat.type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called"<<std::endl;
}

void WrongCat::makeSound() const
{
    std::cout<<"Meow"<<std::endl;
}