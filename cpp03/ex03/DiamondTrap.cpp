/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:20:12 by phanta            #+#    #+#             */
/*   Updated: 2024/06/11 11:06:25 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout<<"DiamondTrap default constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    std::cout<<"DiamondTrap name constructor called"<<std::endl;
    this->name=name;
    this->hit_points=FragTrap::hit_points;
    this->energy_points=ScavTrap::energy_points;
    this->attack_damage=FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond) : ClapTrap(diamond), FragTrap(diamond), ScavTrap(diamond)
{
    std::cout<<"DiamondTrap copy constructor called"<<std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamond)
{
	ClapTrap::operator=(diamond);
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap destructor called"<<std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout<<"I am: "<<this->name<<" as DiamondTrap and "<<ClapTrap::name<<" as ClapTrap"<<std::endl;
}