/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:43:14 by phanta            #+#    #+#             */
/*   Updated: 2024/06/11 10:14:32 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout<<"FragTrap default constructor called"<<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"FragTrap name constructor called"<<std::endl;
    this->hit_points=100;
    this->energy_points=100;
    this->attack_damage=30;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag)
{
    std::cout<<"FragTrap copy constructor called"<<std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &frag)
{
	ClapTrap::operator=(frag);
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout<<"FragTrap destructor called"<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<"FragTrap "<<this->name<<" wants a high five!"<<std::endl;
}

