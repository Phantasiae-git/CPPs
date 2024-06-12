/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:44:12 by phanta            #+#    #+#             */
/*   Updated: 2024/06/10 13:41:37 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
    std::cout<<"ScavTrap default constructor called"<<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout<<"ScavTrap name constructor called"<<std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
    std::cout<<"ScavTrap copy constructor called"<<std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scav)
{
	ClapTrap::operator=(scav);
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap destructor called"<<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->hit_points>0 && this->energy_points>0)
    {
        std::cout<<"ScavTrap "<< this->name<<" attacks " <<target<<", causing "<<this->attack_damage<<" points of damage!"<<std::endl;
        this->energy_points--;
        return;
    }
    std::cout<<"Not enough hit points or energy points to attack!"<<std::endl;
}

void ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<this->name<<" is now in Gate keeper mode"<<std::endl;
}