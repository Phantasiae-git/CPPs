/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:56:24 by phanta            #+#    #+#             */
/*   Updated: 2024/06/11 09:37:50 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << b << std::endl;

Fixed c=b;
if(c==b)
    std::cout << "equal" << std::endl;
else
    std::cout << "hehe" << std::endl;

Fixed num1(14.5f);
Fixed d=b+num1;
std::cout << d << std::endl;
d=b-num1;
std::cout << d << std::endl;
d=b*num1;
std::cout << d << std::endl;
d=num1/b;
std::cout << d << std::endl;
return 0;
}