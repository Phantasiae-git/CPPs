/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:42:52 by phanta            #+#    #+#             */
/*   Updated: 2024/10/30 23:38:03 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"

std::string types[] = {"char: ", "int: ", "float: ", "double: "};

void printChar(std::string const &input, int nd)
{
	std::cout << types[0];
	if(nd)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<unsigned char>(input[0]) << std::endl;
	std::cout << types[1];
	std::cout << static_cast<int>(input[0]) << std::endl;
	std::cout << types[2];
	std::cout << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << types[0];
	std::cout << static_cast<double>(input[0]) << std::endl;
};

void printFloat(std::string const &input, int oor, int oorf)
{
	std::cout << types[0];
	double inputd=atof(input.c_str());
	if ( inputd < 0 || inputd > 127)
		std::cout << "impossible" << std::endl;
	else if(!isprint(inputd))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(inputd) << std::endl;
	std::cout << types[1];
	if(oor)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(inputd) << std::endl;
	std::cout << types[2];
	if(oorf)
	{
		std::cout << "impossible" << std::endl;
		std::cout << types[3];
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<float>(inputd) << "f" << std::endl;
		std::cout << types[3];
		std::cout << inputd << std::endl;
	}
};

void printDouble(std::string const &input, int oor, int oorf)
{
	std::cout << types[0];
	double inputd=atof(input.c_str());
	if ( inputd < 0 || inputd > 127)
		std::cout << "impossible" << std::endl;
	else if(!isprint(inputd))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(inputd) << std::endl;
	std::cout << types[1];
	if(oor)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(inputd) << std::endl;
	std::cout << types[2];
	if(oorf)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(inputd) << "f" << std::endl;
	std::cout << types[3];
	std::cout << static_cast<double>(inputd) << std::endl;
};

void printInt(std::string const &input, int oor)
{
	std::cout << types[0];
	int inputd=atoi(input.c_str());
	if ( inputd < 0 || inputd > 127)
		std::cout << "impossible" << std::endl;
	else if(!isprint(inputd))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(inputd) << std::endl;
	std::cout << types[1];
	if(oor)
	{
		std::cout << "impossible" << std::endl;
		std::cout << types[2];
		std::cout << "impossible" << std::endl;
		std::cout << types[3];
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(inputd) << std::endl;
		std::cout << types[2];
		std::cout << static_cast<float>(inputd) << "f" << std::endl;
		std::cout << types[3];
		std::cout << static_cast<double>(inputd) << std::endl;
	}	
};

void printTrash()
{
	for(int i=0;i<4;i++)
		std::cout << types[i] << "impossible" << std::endl;
};

void printPseudo(std::string const &input)
{
	std::cout << types[0];
	std::cout << "impossible" << std::endl;
	std::cout << types[1];
	std::cout << "impossible" << std::endl;
	if(input=="nan" || input=="nanf")
	{
		std::cout << types[2];
		std::cout << "nanf" << std::endl;
		std::cout << types[3];
		std::cout << "nan" << std::endl;
	}
	if(input=="-inf" || input=="-inff")
	{
		std::cout << types[2];
		std::cout << "-inff" << std::endl;
		std::cout << types[3];
		std::cout << "-inf" << std::endl;
	}
	if(input=="+inf" || input=="+inff")
	{
		std::cout << types[2];
		std::cout << "+inff" << std::endl;
		std::cout << types[3];
		std::cout << "+inf" << std::endl;
	}
};

int typeCheck(std::string const &str, int &oor, int &nd, int &oorf)
{
	if(str=="+inf" || str=="-inf" || str=="+inff" || str=="-inff" || str=="nan" || str=="nanf")
		return 6;
	if(str.length() == 1 && str.find_first_of("0123456789")==std::string::npos)//char
	{
		if(!std::isprint(static_cast<unsigned char>(str[0])))
			nd=1;
		return 1;
	}
	std::cout << std::fixed << std::setprecision(1);
	if(str.find_first_not_of("-0123456789.f") == std::string::npos)
	{
		if(str.find_first_of("-") != std::string::npos && (str.find_first_of("-")!=0 || str.find_first_of("-")!=str.find_last_of("-")))
			return 5;
		double n= atof(str.c_str());
		if(n>std::numeric_limits<int>::max() || n<std::numeric_limits<int>::min())
			oor=1;
		if(n>std::numeric_limits<float>::max() || n<-(std::numeric_limits<float>::max()))
			oorf=1;
		if(str.find_first_not_of("-0123456789") == std::string::npos)//int
			return 2;
		else if(str.find_first_of(".")!=std::string::npos && str.find_first_of(".")==str.find_last_of(".") && str.find_first_of(".")!=(str.length()-1))
		{
			if(str.find_first_of("f") == std::string::npos)//double
				return 4;
			else if(str.find_first_of("f") == (str.length()-1))//float
				return 3;
			else
				return 5;
		}
	}
	return 5;
}
