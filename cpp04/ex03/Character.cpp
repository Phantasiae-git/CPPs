/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:09:15 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 15:11:56 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout<<"Character default constructor called"<<std::endl;
}

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
    std::cout<< "Character "<<this->name<<" created"<<std::endl;
}

Character::Character(const Character &character)
{
    std::cout<<"Character copy constructor called"<<std::endl;
    this->name=character.name;
    for (int i=0; i<4; i++)
    {
        if(inventory[i]!=NULL)
            delete inventory[i];
    }
    for (int i=0;i<4;i++)
	{
		if (character.inventory[i])
			this->inventory[i] = character.inventory[i]->clone();
	}
    
}

Character&  Character::operator=(const Character &character)
{
    this->name=character.name;
    for(int i=0; i<4; i++)
    {
        if(this->inventory[i])
            delete this->inventory[i];
    }
    for(int i=0;i<4;i++)
	{
		if (character.inventory[i])
			this->inventory[i] = character.inventory[i]->clone();
	}
    return(*this);
}

Character::~Character()
{
    std::cout<<"Character destructor called"<<std::endl;
    for(int i=0; i<4; i++)
    {
        if(this->inventory[i])
            delete this->inventory[i];
    }
}

void    Character::equip(AMateria* m)
{
	if (!m)
		return;
    for(int i=0; i<4; i++)
        if(this->inventory[i]==NULL)
        {
            this->inventory[i]=m;
            std::cout<<"Character "<<this->name<<" equipped "<<m->getType()<<std::endl;
            return;
        }
}

void    Character::unequip(int idx)
{
    if(idx<0 || idx>3)
		return;
    if (this->inventory[idx])
    {
        std::cout<<"Character "<<this->name<<" unequipped "<<this->inventory[idx]->getType()<<std::endl;
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if(idx<0 || idx>3)
		return;
    if (inventory[idx]!=NULL)
        inventory[idx]->use(target);
}

std::string const& Character::getName() const {
    return(this->name);
}