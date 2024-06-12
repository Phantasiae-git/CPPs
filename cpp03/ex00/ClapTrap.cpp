/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:01:10 by phanta            #+#    #+#             */
/*   Updated: 2024/06/10 12:41:16 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout<<"Name constructor called"<<std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"Destructor called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this=clap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap)
{
    this->name = clap.name;
    this->hit_points = clap.hit_points;
    this->energy_points = clap.energy_points;
    this->attack_damage = clap.attack_damage;
    return(*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(this->hit_points>0 && this->energy_points>0)
    {
        std::cout<<"ClapTrap "<< this->name<<" attacks " <<target<<", causing "<<this->attack_damage<<" points of damage!"<<std::endl;
        this->energy_points--;
        return;
    }
    std::cout<<"Not enough hit points or energy points to attack!"<<std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points>0)
	{
		std::cout<<"ClapTrap "<< this->name<< " took " <<amount<<" point(s) of damage!"<< std::endl;
		this->hit_points -= amount;
	}
	else
		std::cout<<"ClapTrap "<< this->name<< " is already dead"<< std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->energy_points>0)
	{
		std::cout<<"ClapTrap "<< this->name<< " restored " << amount<< " point(s)!" << std::endl;
		this->hit_points += amount;
		this->energy_points--;
        return;
	}
	std::cout<<"Not enough energy points to repair!"<<std::endl;
}