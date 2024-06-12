/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:46:35 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 15:42:18 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout<<"Cure default constructor called"<<std::endl;
}

Cure::~Cure(void)
{
	std::cout<<"Cure destructor called"<<std::endl;
}

Cure::Cure(const Cure &cure): AMateria(cure)
{
	std::cout<<"Cure copy constructor called"<<std::endl;
}

Cure	&Cure::operator=(const Cure &cure)
{
	this->type = cure.type;
	return(*this);
}

AMateria	*Cure::clone(void) const
{
	return(new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}