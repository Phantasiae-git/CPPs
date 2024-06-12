/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:28:08 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 14:04:20 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout<<"AMateria default constructor called"<<std::endl;
}

AMateria::AMateria( std::string const & type )  : type(type)
{
    std::cout<<"AMateria type constructor called"<<std::endl;
}

AMateria::AMateria(const AMateria&amateria)
{
    *this = amateria;
}

AMateria const	&AMateria::operator=(const AMateria&amateria)
{
	this->type=amateria.type;
	return(*this);
}

AMateria::~AMateria( void )
{
    std::cout<<"AMateria destructor called"<<std::endl;
}

std::string const	&AMateria::getType(void) const
{
	return (this->type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout<<"AMateria "<< this->type <<" used on "<<target.getName()<<std::endl;
}