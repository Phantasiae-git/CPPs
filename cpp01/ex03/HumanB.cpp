/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:37:13 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 18:20:56 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name=name;
    this->weapon=NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    std::cout<<this->name<<" attacks with their "<<this->weapon->getType()<<std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon=&weapon;
}