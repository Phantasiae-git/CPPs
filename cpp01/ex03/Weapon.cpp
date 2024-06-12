/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:32:36 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 18:04:46 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string type)
{
    this->type=type;
}

Weapon::~Weapon()
{
}

void  Weapon::setType(std::string newtype)
{
    this->type=newtype;
}

const std::string&  Weapon::getType()
{
    return(this->type);
}