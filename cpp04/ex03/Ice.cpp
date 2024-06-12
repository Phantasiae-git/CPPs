/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:38:43 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 15:42:27 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout<<"Ice default constructor called"<<std::endl;
}

Ice::~Ice(void)
{
	std::cout<<"Ice destructor called"<<std::endl;
}

Ice::Ice(const Ice &ice): AMateria(ice)
{
	std::cout<<"Ice copy constructor called"<<std::endl;
}

Ice	&Ice::operator=(const Ice &ice)
{
	this->type = ice.type;
	return(*this);
}

AMateria	*Ice::clone(void) const
{
	return(new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}