/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:50:33 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 16:19:10 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout<<this->name<<" destroyed!"<<std::endl;
}

std::string  Zombie::getName() const
{
    return(this->name);
}

void    Zombie::setName(std::string n)
{
    this->name=n;
}

void Zombie::announce( void )
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}