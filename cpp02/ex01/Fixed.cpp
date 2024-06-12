/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:09:45 by phanta            #+#    #+#             */
/*   Updated: 2024/06/10 10:22:08 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac_bits=8;

Fixed::Fixed() : _value(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const int n) : _value(n<<_frac_bits)
{
    std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float n) : _value(roundf(n*(1<<_frac_bits)))
{
    std::cout<<"Float constructor called"<< std::endl;
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout<<"Copy constructor called"<<std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->_value=fixed.getRawBits();

    return(*this);
}

int Fixed::getRawBits( void ) const
{
    return(this->_value);
}

void Fixed::setRawBits( int const raw )
{
    this->_value=raw;
}

float Fixed::toFloat( void ) const
{
     return ((float)_value / (1<<_frac_bits));
}

int Fixed::toInt( void ) const
{
    return (_value>>_frac_bits);
}

std::ostream	&operator<<(std::ostream &s, const Fixed &n)
{
    return (s<<n.toFloat());
}