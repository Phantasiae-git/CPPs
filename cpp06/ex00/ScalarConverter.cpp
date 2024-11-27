/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:28:55 by phanta            #+#    #+#             */
/*   Updated: 2024/10/30 23:36:58 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this=other;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		*this=other;
	return *this;
}

void	ScalarConverter::convert(std::string const &input)
{
	int oor=0;
	int oorf=0;
	int nd=0;
	int type=typeCheck(input, oor, nd, oorf);
	switch (type)
	{
	case 1://char
		printChar(input, nd);
		break;
	case 2://int
		printInt(input, oor);
		break;
	case 3://float
		printFloat(input, oor, oorf);
		break;
	case 4://double
		printDouble(input, oor, oorf);
		break;
	case 5://trash
		printTrash();
		break;
	case 6://pseudo
		printPseudo(input);
		break;
	}
}
